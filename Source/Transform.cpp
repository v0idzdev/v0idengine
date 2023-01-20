#include "Transform.hpp"

namespace v0id::component {

Transform::Transform(Object* owner)
  : Component(owner)
  , position(0.f, 0.f)
{
}

void
Transform::setPosition(float x, float y)
{
  position.x = x;
  position.y = y;
}

void
Transform::setPosition(const sf::Vector2f& pos)
{
  position = pos;
}

void
Transform::addPosition(float x, float y)
{
  position.x += x;
  position.y += y;
}

void
Transform::addPosition(sf::Vector2f pos)
{
  position += pos;
}

void
Transform::setX(float x)
{
  position.x = x;
}

void
Transform::setY(float y)
{
  position.y = y;
}

void
Transform::addX(float x)
{
  position.x += x;
}

void
Transform::addY(float y)
{
  position.y += y;
}

const sf::Vector2f&
Transform::getPosition() const
{
  return position;
}

}