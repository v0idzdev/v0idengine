#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Component.hpp"
#include "ResourceAllocator.hpp"
#include "Transform.hpp"

namespace v0id::component {

/**
 * @brief A renderable image to be added to an Object
 *
 */
class Sprite : public Component
{
public:
  /**
   * @brief Construct a new Sprite object
   *
   * @param owner The Object to add the Sprite to
   */
  Sprite(Object* owner);

  /**
   * @brief Assign the sprite component a texture allocator
   *
   * @param allocator The allocator
   */
  void setTextureAllocator(ResourceAllocator<sf::Texture>* allocator);

  /**
   * @brief Load the sprite from an image file
   *
   * @param filePath The path of the image file
   */
  void load(const std::string& filePath);

  /**
   * @brief Load the sprite from a
   *
   * @param id
   */
  void load(int id);

  /**
   * @brief Execute post-update logic for the Sprite after each frame
   *
   * @param deltaTime The number of seconds since the last frame
   */
  void lateUpdate(float deltaTime) override;

  /**
   * @brief Draw the sprite on-screen each frame
   *
   * @param window The window used to display drawables
   */
  void draw(Window& window) override;

private:
  ResourceAllocator<sf::Texture>* allocator;
  sf::Sprite sprite;
};

}

#endif