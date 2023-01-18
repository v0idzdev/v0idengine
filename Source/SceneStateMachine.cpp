#include "SceneStateMachine.hpp"

SceneStateMachine::SceneStateMachine()
  : scenes(0)
  , currentScene(0)
{
}

SceneStateMachine::~SceneStateMachine() {}

void
SceneStateMachine::processInput()
{
  if (currentScene)
    currentScene->processInput();
}

void
SceneStateMachine::update(float deltaTime)
{
  if (currentScene)
    currentScene->update(deltaTime);
}

void
SceneStateMachine::lateUpdate(float deltaTime)
{
  if (currentScene)
    currentScene->lateUpdate(deltaTime);
}

void
SceneStateMachine::draw(Window& window)
{
  if (currentScene)
    currentScene->draw(window);
}

unsigned int
SceneStateMachine::add(std::shared_ptr<Scene> scene)
{
  auto inserted = scenes.insert(std::make_pair(insertedSceneID, scene));
  inserted.first->second->onCreate();
  return insertedSceneID++;
}

void
SceneStateMachine::remove(unsigned int id)
{
  auto it = scenes.find(id);
  bool sceneFound = it != scenes.end();

  if (sceneFound) {
    // Current scene is the scene pointed to by the ID we found, which is in
    // turn pointed to by the iterator returned from scenes.find(id)
    if (currentScene == it->second)
      currentScene = nullptr;

    it->second->onDestroy();
    scenes.erase(it);
  }
}

void
SceneStateMachine::switchTo(unsigned int id)
{
  auto it = scenes.find(id);
  bool sceneFound = it != scenes.end();

  if (sceneFound) {
    auto scene = it->second;

    // Check comment in SceneStateMachine::remove(). Same applies here
    if (currentScene == it->second) {
      currentScene->onDeactivate();
    }

    currentScene = it->second;
    currentScene->onActivate();
  }
}