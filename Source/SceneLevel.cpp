#include "SceneLevel.hpp"

SceneLevel::SceneLevel(ResourcePath& resourcePath)
  : resourcePath(resourcePath)
{
}

SceneLevel::~SceneLevel() {}

void
SceneLevel::onCreate()
{
  // TODO: Load content
}

void
SceneLevel::onDestroy()
{
}

void
SceneLevel::processInput()
{
  input.update();

  // TODO: Process input
}

void
SceneLevel::update(float deltaTime)
{
  // TODO: Update state
}

void
SceneLevel::draw(Window& window)
{
  // TODO: Draw assets
}