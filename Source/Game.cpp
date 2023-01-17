#include "Game.hpp"

vm::Game::Game()
  : window("My Game")
{
}

void
vm::Game::update()
{
  window.update();
}

void
vm::Game::lateUpdate()
{
}

void
vm::Game::draw()
{
}

bool
vm::Game::isRunning() const
{
  return window.isOpen();
}