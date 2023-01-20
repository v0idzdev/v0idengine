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
}

void
Sprite::lateUpdate(float deltaTime)
{
  // sprite.setPosition(owner->transform->GetPosition());

  auto transform = owner->getComponent<Transform>();
  sprite.setPosition(transform->getPosition());
}

void
Sprite::draw(Window& window)
{
  window.draw(sprite);
}

}