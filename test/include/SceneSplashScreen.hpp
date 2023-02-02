#ifndef SCENE_SPLASH_SCREEN_HPP
#define SCENE_SPLASH_SCREEN_HPP

#include <v0idengine/v0idengine.hpp>

class SceneSplashScreen : public v0id::Scene
{
public:
  SceneSplashScreen(v0id::ResourcePath& resourcePath,
                    v0id::SceneStateMachine& sceneManager,
                    v0id::Window& window);
  ~SceneSplashScreen();

  void onCreate() override;
  void onDestroy() override;
  void onActivate() override;
  void setSwitchToScene(unsigned int id);
  void update(float deltaTime) override;
  void draw(v0id::Window& window) override;

private:
  sf::Texture splashTexture;
  sf::Sprite splashSprite;

  v0id::ResourcePath& resourcePath;
  v0id::SceneStateMachine& sceneManager;
  v0id::Window& window;

  float showForSeconds; // How long to show the splash screen for
  float currentSeconds; // How long the splash screen has been shown for
  unsigned int switchToState;
};

#endif