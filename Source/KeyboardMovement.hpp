#ifndef C_KeyboardMovement_hpp
#define C_KeyboardMovement_hpp

#include "Component.hpp"
#include "Input.hpp"

namespace v0id::component {

class KeyboardMovement : public Component
{
public:
  KeyboardMovement(Object* owner);

  void setInput(Input* input);
  void setMovementSpeed(int moveSpeed);

  void update(float deltaTime) override;

private:
  int moveSpeed;
  Input* input;
};

}

#endif