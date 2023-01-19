# //v0idengine
A lightweight game engine for small 2D titles, with minimal overhead.

### Getting started
Windows is not supported yet. These instructions are for Linux.

1. Install 
```bash
git clone https://github.com/matthewflegg/v0idengine
cd v0idengine
sudo make install
```

2. Create project
```bash
mkdir MyGame/{Source,Resources}
cd MyGame
touch Main.cpp Source/{Game.cpp,Game.hpp,SceneLevel.cpp,SceneLevel.hpp} Makefile
```

3. Add boilerplate

`Main.cpp`
```cpp
#include "Source/Game.hpp"

int main() {
  Game game;

  while (game.isRunning()) {
    game.captureInput();
    game.update();
    game.lateUpdate();
    game.draw();
    game.calculateDeltaTime();
  }

  return 0;
}
```
`Source/Game.hpp`
```cpp
#ifndef GAME_HPP
#define GAME_HPP

#include "SceneLevel.hpp"
#include <v0idengine/Input.hpp>
#include <v0idengine/ResourcePath.hpp>
#include <v0idengine/SceneStateMachine.hpp>
#include <v0idengine/Window.hpp>

class Game
{
public:
  // Create a new game instance
  Game();
  ~Game();
  
  void captureInput();
  void update();
  void lateUpdate();
  void draw();
  void calculateDeltaTime();
  bool isRunning() const;

private:
  v0id::Window window;
  v0id::ResourcePath resourcePath;
  v0id::Input input;
  v0id::SceneStateMachine sceneManager;

  sf::Clock clock;
  float deltaTime;
};

#endif
```
`Source/Game.cpp`
```cpp
#include "Game.hpp"

Game::Game()
  : window("My Game")
{
  // TODO: Add your scenes here
  
  std::shared_ptr<SceneLevel> level =
    std::make_shared<SceneLevel>(resourcePath);

  unsigned int id = sceneManager.add(level);
  sceneManager.switchTo(id);

  // TODO: Add additional loading code here

  deltaTime = clock.restart().asSeconds();
}

Game::~Game() {}

void
Game::captureInput()
{
  sceneManager.processInput();
}

void
Game::update()
{
  window.update();
  sceneManager.update(deltaTime);
}

void
Game::lateUpdate()
{
  sceneManager.lateUpdate(deltaTime);
}

void
Game::draw()
{
  window.beginDraw();
  sceneManager.draw(window);
  window.endDraw();
}

void
Game::calculateDeltaTime()
{
  deltaTime = clock.restart().asSeconds();
}

bool
Game::isRunning() const
{
  return window.isOpen();
}
```
`SceneLevel.hpp`
```cpp
#ifndef SCENELEVEL_HPP
#define SCENELEVEL_HPP

#include <v0idengine/Input.hpp>
#include <v0idengine/ResourcePath.hpp>
#include <v0idengine/Scene.hpp>

class SceneLevel : public v0id::Scene
{
public:
  SceneLevel(v0id::ResourcePath& resourcePath);
  ~SceneLevel();

  void onCreate() override;
  void onDestroy() override;
  void processInput() override;
  void update(float deltaTime) override;
  void draw(v0id::Window& window) override;

private:
  // TODO: Place sprites and scene variables here

  v0id::ResourcePath& resourcePath;
  v0id::Input input;
};

#endif
```
`SceneLevel.cpp`
```cpp
#include "SceneLevel.hpp"

SceneLevel::SceneLevel(v0id::ResourcePath& resourcePath)
  : resourcePath(resourcePath)
{
}

SceneLevel::~SceneLevel() {}

void
SceneLevel::onCreate()
{
  // TODO: Load content
}

void
SceneLevel::onDestroy()
{
}

void
SceneLevel::processInput()
{
  input.update();

  if (input.isKeyPressed(v0id::Input::Key::Esc))
    exit(0);

  // TODO: Process input
}

void
SceneLevel::update(float deltaTime)
{
  // TODO: Update state
}

void
SceneLevel::draw(v0id::Window& window)
{
  // TODO: Draw assets
}
```

## API
v0idengine works by creating a `Game` instance, which contains a `Window` (for rendering) and a `SceneStateMachine` (for switching scenes). Scenes will contain your update logic, drawing logic, and assets, while `Game` will contain your scene management code.

### Scenes

#### Creating scenes
Scenes are created by overriding `Scene`. Add your game logic in `update()`, drawing code in `draw()`, and assets as private variables. 
```cpp
#ifndef MYSCENE_HPP
#define MYSCENE_HPP

#include <v0idengine/Input.hpp>
#include <v0idengine/ResourcePath.hpp>
#include <v0idengine/Scene.hpp>

class MyScene : public Scene
{
public:
  MyScene(ResourcePath& resourcePath);
  ~MyScene();

  void onCreate() override;
  void onDestroy() override;
  void processInput() override;
  void update(float deltaTime) override;
  void draw(Window& window) override;

private:
  // TODO: Place sprites and scene variables here

  ResourcePath& resourcePath;
  Input input;
};

#endif
```

#### Adding scenes
Adding one looks like this:
```cpp
Game::Game()
  : window("My Game")
{
  // Create a shared pointer to your scene
  std::shared_ptr<MyScene> myScene =
    std::make_shared<MyScene>(resourcePath); 
    
  // Add the scene to the SceneStateMachine
  // Its ID will be returned. You need this to switch to or remove the scene
  unsigned int mySceneID = sceneManager.add(myScene);
}
```

#### Switching scenes
Scenes are referenced by their ID. Use it to switch to a scene
```cpp
{
  ...
  
  // Switch to the scene using the ID
  sceneManager.switchTo(mySceneID);
 
  ...
 }
 ```
 
 #### Removing scenes
 You also need the ID to remove scenes
```cpp
{
  ...
  
  // Remove the scene
  sceneManager.remove(mySceneID);
 
  ...
 }
 ```

### Objects and components
Components are simple data containers. Objects are a collection of one or more of these.

#### Creating an object
`.hpp`
```cpp
...

#include <v0idengine/Object.hpp>

class MyScene : public v0id::Scene
{
...

private:
  v0id::Object player;

...
}
```
`.cpp`
```cpp
void
MyScene::onCreate()
{
  player = std::make_shared<Object>();
}
```

#### Adding Components
`.cpp`
```cpp
void
MyScene::onCreate()
{
  ...
  
  // Create a new component
  // Sprite components, in particular, can be loaded
  auto sprite = player->addComponent<v0id::component::Sprite>();
  sprite->load(resourcePath.get() + "player.png");
}

void
MyScene::draw(v0id::Window& window)
{
  // We can also draw sprites
  player->draw(window);
}
```

