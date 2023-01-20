#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Component.hpp"
#include "Transform.hpp"

namespace v0id::component {

class Sprite : public Component
{
public:
  Sprite(Object* owner);

  void load(const std::string& filePath);

  void lateUpdate(float deltaTime) override;
  void draw(Window& window) override;

private:
  sf::Texture texture;
  sf::Sprite sprite;
};

}

#endif