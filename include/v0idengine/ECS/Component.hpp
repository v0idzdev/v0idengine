#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Window.hpp"

namespace v0id {

class Object; // Forward declare

class Component
{
public:
  Component(Object* owner)
    : owner(owner){};

  virtual void awake(){};
  virtual void start(){};
  virtual void update(float deltaTime){};
  virtual void lateUpdate(float deltaTime){};
  virtual void draw(Window& window){};

protected:
  Object* owner;
};

}

#endif