#include "CarMovement.hpp"
#include <v0idengine/Object.hpp>

using v0id::Object, v0id::Input, v0id::component::Transform;

CarMovement::CarMovement(Object* owner)
  : Component(owner)
  , rotation(0.f)
  , speed(0.f)
  , acceleration(0.8f)
  , rps(0.15f)
  , maxSpeed(8.f)
{
}

void
CarMovement::setInput(Input* input)
{
  this->input = input;
}

void
CarMovement::update(float deltaTime)
{
  // We cannot process input w/out an Input instance
  if (input == nullptr)
    return;

  // Steering
  if (input->isKeyPressed(Input::Key::Left)) {
    steerLeft();
  } else if (input->isKeyPressed(Input::Key::Right)) {
    steerRight();
  }

  // Acceleration and braking
  if (input->isKeyPressed(Input::Key::Up)) {
    accelerate();
  } else if (input->isKeyPressed(Input::Key::Down)) {
    decelerate();
  }

  // Update position
  auto transform = owner->getComponent<Transform>();
  transform->addPosition(std::sin(rotation) * speed,
                         std::cos(rotation) * speed);
  // Update rotation? Add rotation to transform?
}

void
CarMovement::accelerate()
{
  speed += acceleration;

  if (speed > maxSpeed)
    speed = maxSpeed;
}

void
CarMovement::decelerate()
{
  speed -= acceleration;

  if (speed < 0)
    speed = 0;
}

void
CarMovement::steerLeft()
{
  rotation -= rps;
}

void
CarMovement::steerRight()
{
  rotation += rps;
}
