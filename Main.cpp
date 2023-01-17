#include "Source/Game.hpp"

int
main()
{
  vm::Game game;

  while (game.isRunning()) {
    game.update();
    game.lateUpdate();
    game.draw();
  }
}
