#ifndef SCENE_HPP
#define SCENE_HPP

#include "Window.hpp"

namespace v0id {

// Abstract base class describing a scene
class Scene
{
public:
  // Called when initially created. Called once per scene
  virtual void onCreate() = 0;
  // Called when scene destroyed. Called once per scene
  virtual void onDestroy() = 0;
  // Called whenever a scene is activated
  virtual void onActivate(){};
  // Called whenever a scene is deactivated
  virtual void onDeactivate(){};

  // Scene input handling goes here
  virtual void processInput(){};
  // Scene update code goes here
  virtual void update(float deltaTime){};
  // Scene post-update code goes here
  virtual void lateUpdate(float deltaTime){};
  // Scene drawing code goes here
  virtual void draw(Window& window){};
};

}

#endif