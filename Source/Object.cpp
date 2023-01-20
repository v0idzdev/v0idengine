#include "Object.hpp"

namespace v0id {

Object::Object()
{
  addComponent<component::Transform>();
}

void
Object::awake()
{
  for (int i = components.size() - 1; i >= 0; i--) {
    components[i]->awake();
  }
}

void
Object::start()
{
  for (int i = components.size() - 1; i >= 0; i--) {
    components[i]->start();
  }
}

void
Object::update(float timeDelta)
{
  for (int i = components.size() - 1; i >= 0; i--) {
    components[i]->update(timeDelta);
  }
}

void
Object::lateUpdate(float timeDelta)
{
  for (int i = components.size() - 1; i >= 0; i--) {
    components[i]->lateUpdate(timeDelta);
  }
}

void
Object::draw(Window& window)
{
  for (int i = components.size() - 1; i >= 0; i--) {
    components[i]->draw(window);
  }
}

}