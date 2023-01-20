#include "SceneLevel.hpp"

SceneLevel::SceneLevel(v0id::ResourcePath& resourcePath)
  : resourcePath(resourcePath)
{
}

SceneLevel::~SceneLevel() {}

void
SceneLevel::onCreate()
{
  // TODO: Load content

  // Create player
  player = std::make_shared<v0id::Object>();

  // Add sprite component
  auto sprite = player->addComponent<v0id::component::Sprite>();
  sprite->load(resourcePath.get() + "car.png");

  // Add input component
  auto movement = player->addComponent<v0id::component::KeyboardMovement>();
  movement->setInput(&input); // Set the Input instance to use
}

void
SceneLevel::onDestroy()
{
}

void
SceneLevel::processInput()
{
  input.update();

  if (input.isKeyPressed(v0id::Input::Key::Esc))
    exit(0);

  // TODO: Process input
}

void
SceneLevel::update(float deltaTime)
{
  // TODO: Update state

  player->update(deltaTime);
}

void
SceneLevel::lateUpdate(float deltaTime)
{
  player->lateUpdate(deltaTime);
}

void
SceneLevel::draw(v0id::Window& window)
{
  // TODO: Draw assets

  player->draw(window);
}