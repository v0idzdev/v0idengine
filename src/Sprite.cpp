#include "Sprite.hpp"
#include "Object.hpp"

namespace v0id::component {

Sprite::Sprite(Object* owner)
  : Component(owner)
{
}

void
Sprite::load(const std::string& filePath)
{
  texture.loadFromFile(filePath);
  sprite.setTexture(texture);
  // All transformations originate from the centre of the sprite
  sprite.setOrigin((sf::Vector2f)texture.getSize() / 2.f);
  sprite.setRotation(0.f);
}

void
Sprite::lateUpdate(float deltaTime)
{
  // sprite.setPosition(owner->transform->GetPosition());

  auto transform = owner->getComponent<Transform>();
  sprite.setPosition(transform->getPosition());
  // Set position and rotation to sprite transform
  sprite.setRotation(transform->getRotation());
  sprite.setScale(transform->getScale());
}

void
Sprite::draw(Window& window)
{
  window.draw(sprite);
}

}