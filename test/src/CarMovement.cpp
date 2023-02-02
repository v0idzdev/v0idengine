#include "CarMovement.hpp"

CarMovement::CarMovement(v0id::Object* owner)
  : v0id::Component(owner)
  , rotation(0.f)
  , speed(0.f)
  , acceleration(0.185f)
  , reverseAcceleration(0.0995f)
  , dps(1.1f)
  , maxSpeed(7.f)
  , maxReverseSpeed(0.8f)
  , brakingPercent(0.17f)
  , engineBrakingPercent(0.01f) // Engine braking per second
  , stationaryThreshold(0.1f)
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
  if (isStationary()) { // Uhhhhh
    if (input->isKeyPressed(v0id::Input::Key::Left)) {
      steerLeft();
    } else if (input->isKeyPressed(v0id::Input::Key::Right)) {
      steerRight();
    }
  }

  // Acceleration and braking
  if (input->isKeyPressed(v0id::Input::Key::Up)) {
    accelerate();
  } else if (input->isKeyPressed(v0id::Input::Key::Down)) {
    if (isReversing()) { // Also uhh
      reverse();
    } else {
      brake();
    }
  }

  // EngineBrakingPercent is the % decrease in speed per second
  speed *= 1 - engineBrakingPercent;

  // Update position
  auto transform = owner->getComponent<v0id::component::Transform>();
  auto rotationRadians = rotation * 3.141592653f / 180.f;
  transform->addPosition(std::sin(rotationRadians) * speed,
                         -std::cos(rotationRadians) * speed);
  transform->setRotation(rotation);
}

void
CarMovement::accelerate()
{
  speed += acceleration;

  if (speed > maxSpeed)
    speed = maxSpeed;
}

void
CarMovement::brake()
{
  speed *= 1 - brakingPercent;
}

void
CarMovement::reverse()
{
  speed -= reverseAcceleration;

  if (speed < -maxReverseSpeed)
    speed = -maxReverseSpeed;
}

void
CarMovement::steerLeft()
{
  if (speed == 0)
    return;

  rotation -= dps;
}

void
CarMovement::steerRight()
{
  if (speed == 0)
    return;

  rotation += dps;
}

bool
CarMovement::isStationary()
{
  return (speed < -stationaryThreshold || speed > stationaryThreshold);
}

bool
CarMovement::isReversing()
{
  return (speed < stationaryThreshold);
}
