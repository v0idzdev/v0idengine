#include "ObjectCollection.hpp"

namespace v0id {

void
ObjectCollection::add(std::shared_ptr<Object> object)
{
  // Add to the array of new objects
  newObjects.push_back(object);
}

void
ObjectCollection::update(float deltaTime)
{
  for (const auto& object : objects) {
    object->update(deltaTime);
  }
}

void
ObjectCollection::lateUpdate(float deltaTime)
{
  for (const auto& object : objects) {
    object->lateUpdate(deltaTime);
  }
}

void
ObjectCollection::draw(Window& window)
{
  for (const auto& object : objects) {
    object->draw(window);
  }
}

void
ObjectCollection::processNew()
{
  // Exit early if there are no new Objects for efficiency
  if (newObjects.size() <= 0) {
    return;
  }

  // Call awake() on each new Object
  for (const auto& newObject : newObjects) {
    newObject->awake();
  }

  // Call start() after calling awake() on each new Object
  for (const auto& newObject : newObjects) {
    newObject->start();
  }

  // Add each new Object to the primary array of Objects, where it will be
  // updated on/after each frame and drawn
  objects.assign(newObjects.begin(), newObjects.end());
  newObjects.clear();
}

void
ObjectCollection::processRemovals()
{
  auto it = objects.begin();

  while (it != objects.end()) {
    auto object = **it;

    if (object.isQueuedForRemoval()) {
      it = objects.erase(it);
    } else {
      ++it;
    }
  }
}

const std::size_t
ObjectCollection::getSize() const
{
  return objects.size();
}

}