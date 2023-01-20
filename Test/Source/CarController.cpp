#include "CarController.hpp"
#include <v0idengine/Object.hpp>

CarMovement::CarMovement(v0id::Object* owner)
  : Component(owner)
  , rotation(0.f)
  , speed(0.f)
  , acceleration(10.f)
  , rps(15.f)
  , maxSpeed(100.f)
{
}

void
CarMovement::setInput(v0id::Input* input)
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
  if (input->isKeyPressed(v0id::Input::Key::Left)) {
    steerLeft();
  } else if (input->isKeyPressed(v0id::Input::Key::Right)) {
    steerRight();
  }

  // Acceleration and braking
  if (input->isKeyPressed(v0id::Input::Key::Up)) {
    accelerate();
  } else if (input->isKeyPressed(v0id::Input::Key::Down)) {
    decelerate();
  }

  // Update position
  auto transform = owner->getComponent<v0id::component::Transform>();
  transform->addPosition(std::sin(rotation) * speed,
                         std::cos(rotation) * speed);
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
