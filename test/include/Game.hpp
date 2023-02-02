#ifndef GAME_HPP
#define GAME_HPP

#include "SceneLevel.hpp"
#include "SceneSplashScreen.hpp"
#include <v0idengine/v0idengine.hpp>

class Game
{
public:
  // Create a new game instance
  Game();
  ~Game();

  // Update input. Process input in update()
  void captureInput();

  // Add update code here
  void update();

  // Add post-update code here
  void lateUpdate();

  // Add drawing code here
  void draw();

  // Calculate delta time
  void calculateDeltaTime();

  // Return true if the game is running
  bool isRunning() const;

private:
  v0id::Window window;
  v0id::ResourcePath resourcePath;
  v0id::Input input;
  v0id::SceneStateMachine sceneManager;
  v0id::ResourceAllocator<sf::Texture> textureAllocator;

  // TODO: Put game sprites and variables here

  sf::Clock clock;
  float deltaTime;
};

#endif