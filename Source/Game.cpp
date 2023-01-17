#include "Game.hpp"

Game::Game()
  : window("My Game")
{
  // TODO: Add loading code here

  deltaTime = clock.restart();
}

Game::~Game() {}

void
Game::captureInput()
{
  input.update();
}

void
Game::update()
{
  window.update();

  // TODO: Add update code here
}

void
Game::lateUpdate()
{
}

void
Game::draw()
{
  window.beginDraw();

  // TODO: Add drawing code here

  window.endDraw();
}

void
Game::calculateDeltaTime()
{
  deltaTime = clock.restart();
}

bool
Game::isRunning() const
{
  return window.isOpen();
}