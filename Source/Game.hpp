#ifndef GAME_HPP
#define GAME_HPP

#include "Input.hpp"
#include "ResourcePath.hpp"
#include "SceneLevel.hpp"
#include "SceneSplashScreen.hpp"
#include "SceneStateMachine.hpp"
#include "Window.hpp"
#include <SFML/Graphics.hpp>

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
  Window window;
  ResourcePath resourcePath;
  Input input;
  SceneStateMachine sceneManager;

  // TODO: Put game sprites and variables here

  sf::Clock clock;
  float deltaTime;
};

#endif