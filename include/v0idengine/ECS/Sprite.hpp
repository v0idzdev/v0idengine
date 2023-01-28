#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Component.hpp"
#include "Transform.hpp"

namespace v0id::component {

/// @brief A renderable image to be added to an Object
class Sprite : public Component
{
public:
  /// @brief Create a new Sprite
  /// @param owner The Object to add the component to
  Sprite(Object* owner);

  /// @brief Load the sprite from an image file
  /// @param filePath The path of the image file
  void load(const std::string& filePath);

  /// @brief Execute post-update logic for the Sprite after each frame
  /// @param deltaTime The number of seconds since the last frame
  void lateUpdate(float deltaTime) override;

  /// @brief Draw the sprite on-screen each frame
  /// @param window The window used to draw drawables
  void draw(Window& window) override;

private:
  sf::Texture texture;
  sf::Sprite sprite;
};

}

#endif