#ifndef GAME_HPP
#define GAME_HPP

#include "Window.hpp"
#include <SFML/Graphics.hpp>

namespace vm {

class Game
{
public:
  Game();

  void update();
  void lateUpdate();
  void draw();
  bool isRunning() const;

private:
  Window window;
};

}; // namespace vm

#endif