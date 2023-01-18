#ifndef SCENESTATEMACHINE_HPP
#define SCENESTATEMACHINE_HPP

#include "EnumHash.hpp"
#include "Scene.hpp"
#include "Window.hpp"
#include <memory>
#include <unordered_map>

class SceneStateMachine
{
public:
  SceneStateMachine();
  ~SceneStateMachine();

  void processInput();
  void update(float deltaTime);
  void lateUpdate(float deltaTime);
  void draw(Window& window);

  // Add a new scene and return its scene ID
  unsigned int add(std::shared_ptr<Scene> scene);
  // Switch to a scene
  void switchTo(unsigned int id);
  // Remove a scene. Calls onDestroy() on the scene with the id passed.
  void remove(unsigned int id);

private:
  std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes;
  std::shared_ptr<Scene> currentScene;
  unsigned int insertedSceneID;
};

#endif