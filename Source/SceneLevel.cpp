#include "SceneLevel.hpp"

SceneLevel::SceneLevel(ResourcePath& resourcePath)
  : resourcePath(resourcePath)
{
}

SceneLevel::~SceneLevel() {}

void
SceneLevel::onCreate()
{
  // TODO: Resource loading code with resourcePath.get() + "filename.png"
}

void
SceneLevel::onDestroy()
{
}

void
SceneLevel::processInput()
{
  input.update();
}

void
SceneLevel::update(float deltaTime)
{
  // TODO: Update code here
}

void
SceneLevel::draw(Window& window)
{
  // TODO: Drawing code using window.draw();
}