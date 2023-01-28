#ifndef C_Transform_hpp
#define C_Transform_hpp

#include "Component.hpp"

namespace v0id::component {

class Transform : public Component
{
public:
  Transform(Object* owner);

  void setPosition(float x, float y);
  void setPosition(const sf::Vector2f& pos);
  void addPosition(float x, float y);
  void addPosition(sf::Vector2f pos);
  void setX(float x);
  void setY(float y);
  void addX(float x);
  void addY(float y);

  void setScale(float x, float y);
  void setScale(const sf::Vector2f& scale);
  void setScaleX(float x);
  void setScaleY(float y);

  void setRotation(float degrees);
  void addRotation(float degrees);

  const sf::Vector2f& getPosition() const;
  const sf::Vector2f& getScale() const;
  // Return rotation in degrees
  const float& getRotation() const;

private:
  sf::Vector2f position, scale;
  float rotation;
};

}

#endif