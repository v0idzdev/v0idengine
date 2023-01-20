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

  const sf::Vector2f& getPosition() const;

private:
  sf::Vector2f position;
};

}

#endif