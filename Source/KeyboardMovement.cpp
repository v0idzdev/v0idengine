#include "KeyboardMovement.hpp"
#include "Object.hpp"

namespace v0id::component {

KeyboardMovement::KeyboardMovement(Object* owner)
  : Component(owner)
  , moveSpeed(100)
{
}

void
KeyboardMovement::setInput(Input* input)
{
  this->input = input;
}

void
KeyboardMovement::setMovementSpeed(int moveSpeed)
{
  this->moveSpeed = moveSpeed;
}

void
KeyboardMovement::update(float deltaTime)
{
  if (input == nullptr) {
    return;
  }

  int xMove = 0;
  if (input->isKeyPressed(Input::Key::Left)) {
    xMove = -moveSpeed;
  } else if (input->isKeyPressed(Input::Key::Right)) {
    xMove = moveSpeed;
  }

  int yMove = 0;
  if (input->isKeyPressed(Input::Key::Up)) {
    yMove = -moveSpeed;
  } else if (input->isKeyPressed(Input::Key::Down)) {
    yMove = moveSpeed;
  }

  float xFrameMove = xMove * deltaTime;
  float yFrameMove = yMove * deltaTime;

  // owner->transform->addPosition(xFrameMove, yFrameMove);

  auto transform = owner->getComponent<Transform>();
  transform->addPosition(xFrameMove, yFrameMove);
}

}