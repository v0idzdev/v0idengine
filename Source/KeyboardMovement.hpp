#ifndef C_KeyboardMovement_hpp
#define C_KeyboardMovement_hpp

#include "Component.hpp"
#include "Input.hpp"

namespace v0id::component {

/// @brief Lets the player move an Object up, down, left, and right
class KeyboardMovement : public Component
{
public:
  /// @brief Create a new KeyboardMovement
  /// @param owner The Object to add the component to
  KeyboardMovement(Object* owner);

  /// @brief Set the Input instance used to detect, store, and control input
  /// @param input The Input instance
  void setInput(Input* input);

  /// @brief Set the movement speed of the Object
  /// @param moveSpeed The movement speed in pixels per second
  void setMovementSpeed(int moveSpeed);

  /// @brief Update the state of the KeyboardMovement on each frame
  /// @param deltaTime The number of seconds since the last frame
  void update(float deltaTime) override;

private:
  int moveSpeed;
  Input* input;
};

}

#endif