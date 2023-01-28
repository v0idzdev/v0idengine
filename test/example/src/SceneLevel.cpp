#include "SceneLevel.hpp"

SceneLevel::SceneLevel(v0id::ResourcePath& resourcePath)
  : resourcePath(resourcePath)
{
}

SceneLevel::~SceneLevel() {}

void
SceneLevel::onCreate()
{
  // Create entity
  player = std::make_shared<v0id::Object>();
  auto sprite = player->addComponent<v0id::component::Sprite>();
  auto controller = player->addComponent<CarMovement>();
  auto transform = player->getComponent<v0id::component::Transform>();

  // Init components
  sprite->load(resourcePath.get() + "car.png");
  controller->setInput(&input);
  transform->setPosition(400, 300);
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