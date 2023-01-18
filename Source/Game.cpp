#include "Game.hpp"

Game::Game()
  : window("My Game")
{
  // Create a splash screen scene
  std::shared_ptr<SceneSplashScreen> splashScreen =
    std::make_shared<SceneSplashScreen>(resourcePath, sceneManager, window);

  // Create a main level scene
  std::shared_ptr<SceneLevel> mainLevel =
    std::make_shared<SceneLevel>(resourcePath);

  unsigned int splashScreenID = sceneManager.add(splashScreen);
  unsigned int mainLevelID = sceneManager.add(mainLevel);
  splashScreen->setSwitchToScene(mainLevelID);
  sceneManager.switchTo(splashScreenID);

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