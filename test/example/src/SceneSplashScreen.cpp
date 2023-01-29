#include "SceneSplashScreen.hpp"

SceneSplashScreen::SceneSplashScreen(v0id::ResourcePath& resourcePath,
                                     v0id::SceneStateMachine& sceneManager,
                                     v0id::Window& window)
  : sceneManager(sceneManager)
  , resourcePath(resourcePath)
  , window(window)
  , switchToState(0)
  , currentSeconds(0.f)
  , showForSeconds(3.f)
{
}

SceneSplashScreen::~SceneSplashScreen() {}

void
SceneSplashScreen::onCreate()
{
  // TODO: Remake logo in a higher resolution and scale down as needed
  splashTexture.loadFromFile(resourcePath.get() + "v0idengine.png");
  splashSprite.setTexture(splashTexture);

  sf::FloatRect spriteSize = splashSprite.getLocalBounds();
  splashSprite.setOrigin(spriteSize.width * 0.5f, spriteSize.height * 0.5f);
  splashSprite.setScale(1.f, 1.f);

  sf::Vector2u windowCentre = window.getCentre();
  splashSprite.setPosition(windowCentre.x, windowCentre.y);
}

void
SceneSplashScreen::onActivate()
{
  currentSeconds = 0.f;
}

void
SceneSplashScreen::onDestroy()
{
}

void
SceneSplashScreen::setSwitchToScene(unsigned int id)
{
  switchToState = id; // Set id of scene to switch to
}

void
SceneSplashScreen::update(float deltaTime)
{
  currentSeconds += deltaTime;

  if (currentSeconds >= showForSeconds)
    sceneManager.switchTo(switchToState);
}

void
SceneSplashScreen::draw(v0id::Window& window)
{
  window.draw(splashSprite);
}