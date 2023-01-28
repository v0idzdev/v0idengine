#ifndef SCENE_STATE_MACHINE_HPP
#define SCENE_STATE_MACHINE_HPP

#include "EnumHash.hpp"
#include "Scene.hpp"
#include "Window.hpp"
#include <memory>
#include <unordered_map>

namespace v0id {

/// @brief Used to store each scene in the game and transition between them
class SceneStateMachine
{
public:
  /// @brief Create a new SceneStateMachine
  SceneStateMachine();
  ~SceneStateMachine();

  /// @brief Call the processInput method of the current Scene
  void processInput();

  /// @brief Call the update method of the current Scene
  /// @param deltaTime The number of seconds since the last frame
  void update(float deltaTime);

  /// @brief Call the lateUpdate method of the current Scene
  /// @param deltaTime The number of seconds since the last frame
  void lateUpdate(float deltaTime);

  /// @brief Call the draw method of the current Scene
  /// @param window The Window used to draw drawables
  void draw(Window& window);

  /// @brief Add a new Scene to the SceneStateMachine
  /// @param scene A shared pointer to the Scene to add
  /// @note Calls the onCreate method of the added scene
  /// @return The ID of the added scene
  unsigned int add(std::shared_ptr<Scene> scene);

  /// @brief Swicth to a Scene that was added to the SceneStateMachine
  /// @note Calls the onDeactivate method of the old scene
  /// @note Calls the onActivate method of the new
  /// @param id The ID of the scene to switch to
  void switchTo(unsigned int id);

  // Remove a scene. Calls onDestroy() on the scene with the id passed.

  /// @brief Remove a Scene that was added to the SceneStateMachine
  /// @note Calls the onDestroy method of the removed scene
  /// @param id The ID of the scene to remove
  void remove(unsigned int id);

private:
  std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
  std::shared_ptr<Scene> currentScene;
  unsigned int insertedSceneID;
};

}

#endif