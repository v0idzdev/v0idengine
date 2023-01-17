#ifndef INPUT_HPP
#define INPUT_HPP

#include "Bitmask.hpp"
#include <SFML/Graphics.hpp>

class Input
{
public:
  enum class Key
  {
    None = 0,
    Left = 1,
    Right = 2,
    Up = 3,
    Down = 4,
    Esc = 5
  };

  void update();

  // Returns true if the key is currently down
  bool isKeyPressed(Key key);

  // Returns true if the key was just pressed
  bool isKeyDown(Key key);

  // Returns true if the key was just released
  bool isKeyUp(Key key);

private:
  Bitmask thisFrameKeys;
  Bitmask lastFrameKeys;
};

#endif