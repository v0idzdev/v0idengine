#include "Transform.hpp"

namespace v0id::component {

Transform::Transform(Object* owner)
  : Component(owner)
  , position(0.f, 0.f)
  , scale(1.f, 1.f)
  , rotation(0.f)
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

void
Transform::setScale(float x, float y)
{
  scale.x = x;
  scale.y = y;
}

void
Transform::setScale(const sf::Vector2f& scale)
{
  this->scale = scale;
}

void
Transform::setScaleX(float x)
{
  scale.x = x;
}

void
Transform::setScaleY(float y)
{
  scale.y = y;
}

void
Transform::setRotation(float degrees)
{
  rotation = degrees;
}

void
Transform::addRotation(float degrees)
{
  rotation = degrees;
}

const sf::Vector2f&
Transform::getPosition() const
{
  return position;
}

const sf::Vector2f&
Transform::getScale() const
{
  return scale;
}

const float&
Transform::getRotation() const
{
  return rotation;
}

}