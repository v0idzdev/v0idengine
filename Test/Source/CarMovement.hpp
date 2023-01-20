#ifndef CARCONTROLLER_HPP
#define CARCONTROLLER_HPP

#include <cmath>
#include <v0idengine/Component.hpp>
#include <v0idengine/Input.hpp>

class CarMovement : public v0id::Component
{
public:
  CarMovement(v0id::Object* owner);

  void setInput(v0id::Input* input);
  void update(float deltaTime) override;

private:
  void accelerate();
  void decelerate();
  void steerLeft();
  void steerRight();

  // Rps: Radians per second - angular accel
  float rotation, speed, acceleration, rps;
  const float maxSpeed;
  v0id::Input* input;
};

#endif