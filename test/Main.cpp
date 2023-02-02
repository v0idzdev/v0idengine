#include "Game.hpp"

int
main()
{
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