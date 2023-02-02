#include "SceneLevel.hpp"

SceneLevel::SceneLevel(v0id::ResourcePath& resourcePath,
                       v0id::ResourceAllocator<sf::Texture>& textureAllocator)
  : resourcePath(resourcePath)
  , textureAllocator(textureAllocator)
{
}

SceneLevel::~SceneLevel() {}

void
SceneLevel::onCreate()
{
  // // Create entity
  // player = std::make_shared<v0id::Object>();

  // // Init components
  // sprite->load(resourcePath.get() + "car.png");
  // controller->setInput(&input);
  // transform->setPosition(400, 300);

  auto player = std::make_shared<v0id::Object>();
  auto sprite = player->addComponent<v0id::component::Sprite>();
  sprite->setTextureAllocator(&textureAllocator);
  sprite->load(textureAllocator.add(resourcePath.get() + "car.png"));

  auto controller = player->addComponent<CarMovement>();
  controller->setInput(&input);

  objects.add(player);
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
  objects.processRemovals();
  objects.processNew();

  // TODO: Update state

  objects.update(deltaTime);
}

void
SceneLevel::lateUpdate(float deltaTime)
{
  objects.lateUpdate(deltaTime);
}

void
SceneLevel::draw(v0id::Window& window)
{
  // TODO: Draw assets

  objects.draw(window);
}