#ifndef GAME_HPP
#define GAME_HPP

#include "SceneLevel.hpp"
#include "SceneSplashScreen.hpp"
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

  // TODO: Put game sprites and variables here

  sf::Clock clock;
  float deltaTime;
};

#endif