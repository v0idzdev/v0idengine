#ifndef INPUT_HPP
#define INPUT_HPP

#include "Bitmask.hpp"
#include <SFML/Graphics.hpp>

namespace v0id {

/// @brief Used to detect, store, and query user input
class Input
{
public:
  /// @brief Stores the value of the name of a key (or a collection of keys)
  enum class Key
  {
    /// @brief No keys
    None = 0,

    /// @brief Either A or the left arrow key
    Left = 1,

    /// @brief Either D or the right arrow key
    Right = 2,

    /// @brief Either W or the up arrow key
    Up = 3,

    /// @brief Either S or the down arrow key
    Down = 4,

    /// @brief The escape key
    Esc = 5
  };

  /// @brief Update the state of the Input on each frame
  void update();

  /// @brief Determine whether a key is currently down
  /// @param key The key
  /// @return True if the key is currently down
  bool isKeyPressed(Key key);

  /// @brief Determine whether a key was just pressed
  /// @param key The key
  /// @return True if the key was just pressed
  bool isKeyDown(Key key);

  /// @brief Determine whether a key was just released
  /// @param key The key
  /// @return True if the key was just released
  bool isKeyUp(Key key);

private:
  Bitmask thisFrameKeys;
  Bitmask lastFrameKeys;
};

}

#endif