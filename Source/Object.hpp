#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Component.hpp"
#include "Transform.hpp"
#include "Window.hpp"
#include <memory>
#include <vector>

namespace v0id {

/// @brief A collection of components that, together, form a game entity
class Object
{
public:
  /// @brief Create a new Object
  Object();

  /// @brief Called when the object is created
  void awake();

  /// @brief Called after the Awake method
  void start();

  /// @brief Call the update method of each component on each frame
  /// @param deltaTime The number of seconds since the last frame
  void update(float deltaTime);

  /// @brief Call the lateUpdate method of each component on each frame
  /// @param deltaTime The number of seconds since the last frame
  void lateUpdate(float deltaTime);

  /// @brief Call the draw method of each component on each frame
  /// @param window A rendering window
  void draw(Window& window);

  /// @brief Add a new component to the Object
  /// @tparam T The component to add
  /// @return An instance of the added component
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

  /// @brief Get an existing component that was added to the Object
  /// @tparam T The component to get
  /// @return The instance of the component, or nullptr if not found
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