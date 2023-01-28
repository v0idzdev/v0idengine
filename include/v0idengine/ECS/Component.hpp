#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Window.hpp"

namespace v0id {

class Object; // Forward declare

// Abstract base class for v0idengine components
class Component
{
public:
  /// @brief Create a new Component
  /// @param owner The Object to add the component to
  Component(Object* owner)
    : owner(owner){};

  /// @brief Called when the Component is created
  virtual void awake(){};

  /// @brief Called after the awake method
  virtual void start(){};

  /// @brief Update this or other Components on each frame
  /// @param deltaTime The number of seconds since the last frame
  virtual void update(float deltaTime){};

  /// @brief Update this or other Components after each frame
  /// @param deltaTime The number of seconds since the last frame
  virtual void lateUpdate(float deltaTime){};

  /// @brief Draw the component to the window
  /// @param window A window used to display drawables
  virtual void draw(Window& window){};

protected:
  Object* owner;
};

}

#endif