#ifndef OBJECT_COLLECTION_HPP
#define OBJECT_COLLECTION_HPP

#include "Object.hpp"
#include <memory>
#include <vector>

namespace v0id {

class ObjectCollection
{
public:
  void add(std::shared_ptr<Object> object);

  /**
   * @brief Update each object in the collection on each frame
   *
   * @param deltaTime The number of seconds since the last frame
   */
  void update(float deltaTime);

  /**
   * @brief Update each object in the collection after each frame
   *
   * @param deltaTime The number of seconds since the last frame
   */
  void lateUpdate(float deltaTime);

  /**
   * @brief Draw each object in the collection that has a drawable component
   * @note For the object to be drawn, it must have either a Sprite component
   * or a user-defined component that is drawable
   *
   * @param window The window used to render drawables
   */
  void draw(Window& window);

  /**
   * @brief Process objects added this frame
   * @note Enables objects added this frame to be updated, drawn, etc. Normally,
   * this is called at the beginning or end of a frame
   */
  void processNew();

  /**
   * @brief Remove Objects that are queued for removal
   *
   */
  void processRemovals();

private:
  std::vector<std::shared_ptr<Object>> objects;
  std::vector<std::shared_ptr<Object>> newObjects;
};

}

#endif