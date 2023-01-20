#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Component.hpp"
#include "Window.hpp"
#include <memory>
#include <vector>

namespace v0id {

class Object
{
public:
  void awake(); // Called when object is created
  void start(); // Called after awake

  void update(float deltaTime);
  void lateUpdate(float deltaTime);
  void draw(Window& window);

  template<typename T>
  std::shared_ptr<T> addComponent()
  {
    static_assert(std::is_base_of<Component, T>::value,
                  "T must derive from Component");

    // Return existing component of this type if we already have one
    for (auto& component : components)
      if (std::dynamic_pointer_cast<T>(component))
        return std::dynamic_pointer_cast<T>(component);

    std::shared_ptr<T> newComponent = std::make_shared<T>(this);
    components.push_back(newComponent);
    return newComponent;
  }

  template<typename T>
  std::shared_ptr<T> getComponent()
  {
    // Return existing component of this type if we already have one
    for (auto& component : components)
      if (std::dynamic_pointer_cast<T>(component))
        return std::dynamic_pointer_cast<T>(component);

    return nullptr;
  }

private:
  std::vector<std::shared_ptr<Component>> components;
};

}

#endif