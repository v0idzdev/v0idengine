#include "Sprite.hpp"
#include "Object.hpp"

namespace v0id::component {

Sprite::Sprite(Object* owner)
  : Component(owner)
{
}

void
Sprite::setTextureAllocator(ResourceAllocator<sf::Texture>* allocator)
{
  this->allocator = allocator;
}

void
Sprite::load(int id)
{
  if (id < 0) {
    return;
  }

  std::shared_ptr<sf::Texture> texture = allocator->get(id);
  sprite.setTexture(*texture);
}

void
Sprite::load(const std::string& filePath)
{
  if (!allocator) {
    return;
  }

  int textureID = allocator->add(filePath);

  if (textureID < 0) {
    return;
  }

  std::shared_ptr<sf::Texture> texture = allocator->get(textureID);
  sprite.setTexture(*texture);

  // All transformations originate from the centre of the sprite
  sprite.setOrigin((sf::Vector2f)texture->getSize() / 2.f);
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