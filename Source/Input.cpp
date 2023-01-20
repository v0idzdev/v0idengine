#include "Input.hpp"

namespace v0id {

void
Input::update()
{
  lastFrameKeys.setMask(thisFrameKeys);

  // Set the left bit if left arrow or A are pressed
  thisFrameKeys.setBit((int)Key::Left,
                       (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) ||
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::A)));

  // Set the right bit if right arrow or D are pressed
  thisFrameKeys.setBit((int)Key::Right,
                       (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) ||
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::D)));

  // Set the right bit if up arrow or W are pressed
  thisFrameKeys.setBit((int)Key::Up,
                       (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) ||
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::W)));

  // Set the right bit if down arrow or S are pressed
  thisFrameKeys.setBit((int)Key::Down,
                       (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) ||
                         (sf::Keyboard::isKeyPressed(sf::Keyboard::S)));

  // Set the esc bit if escape is pressed
  thisFrameKeys.setBit((int)Key::Esc,
                       (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)));
}

bool
Input::isKeyDown(Key key)
{
  bool lastFrame = lastFrameKeys.getBit((int)key);
  bool thisFrame = thisFrameKeys.getBit((int)key);

  // Key down this frame, but up last frame
  return thisFrame && !lastFrame;
}

bool
Input::isKeyPressed(Key key)
{
  // Key down this frame... It doesn't matter if it was up or down last frame
  return thisFrameKeys.getBit((int)key);
}

bool
Input::isKeyUp(Key key)
{
  bool lastFrame = lastFrameKeys.getBit((int)key);
  bool thisFrame = thisFrameKeys.getBit((int)key);

  // Key up this frame, but down last frame
  return !thisFrame && lastFrame;
}

}