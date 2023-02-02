#ifndef CARCONTROLLER_HPP
#define CARCONTROLLER_HPP

#include <cmath>
#include <v0idengine/v0idengine.hpp>

class CarMovement : public v0id::Component
{
public:
  CarMovement(v0id::Object* owner);

  void setInput(v0id::Input* input);
  void update(float deltaTime) override;

private:
  void accelerate();
  void brake();
  void reverse();
  void steerLeft();
  void steerRight();

  bool isStationary();
  bool isReversing();

  // Dps: Degrees per second - angular accel
  float rotation, speed, acceleration, reverseAcceleration, dps;
  const float maxSpeed, maxReverseSpeed, brakingPercent, engineBrakingPercent,
    stationaryThreshold;
  v0id::Input* input;
};

#endif