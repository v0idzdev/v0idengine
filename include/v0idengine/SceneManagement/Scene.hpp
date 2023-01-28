#ifndef SCENE_HPP
#define SCENE_HPP

#include "Window.hpp"

namespace v0id {

// Abstract class that user-created Scenes will override to construct a game
class Scene
{
public:
  /// @brief Called once when the Scene is created
  virtual void onCreate() = 0;

  /// @brief Called once when the Scene is destroyed
  virtual void onDestroy() = 0;

  /// @brief Called each time the Scene is activated
  virtual void onActivate(){};

  /// @brief Called each time the Scene is deactivated
  virtual void onDeactivate(){};

  /// @brief Contains the input management code for the Scene
  virtual void processInput(){};

  /// @brief Update the state of the Scene on each frame
  /// @param deltaTime The number of seconds since the last frame
  virtual void update(float deltaTime){};

  /// @brief Update the state of the Scene after each frame
  /// @param deltaTime The number of seconds since the last frame
  virtual void lateUpdate(float deltaTime){};

  /// @brief Draw drawables in the Scene
  /// @param window The Window used to draw drawables
  virtual void draw(Window& window){};
};

}

#endif