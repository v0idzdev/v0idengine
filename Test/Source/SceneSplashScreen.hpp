#ifndef SCENESPLASHSCREEN_HPP
#define SCENESPLASHSCREEN_HPP

#include <v0idengine/ResourcePath.hpp>
#include <v0idengine/SceneStateMachine.hpp>

class SceneSplashScreen : public Scene
{
public:
  SceneSplashScreen(ResourcePath& resourcePath,
                    SceneStateMachine& sceneManager,
                    Window& window);
  ~SceneSplashScreen();

  void onCreate() override;
  void onDestroy() override;
  void onActivate() override;
  void setSwitchToScene(unsigned int id);
  void update(float deltaTime) override;
  void draw(Window& window) override;

private:
  sf::Texture splashTexture;
  sf::Sprite splashSprite;

  ResourcePath& resourcePath;
  SceneStateMachine& sceneManager;
  Window& window;

  float showForSeconds; // How long to show the splash screen for
  float currentSeconds; // How long the splash screen has been shown for
  unsigned int switchToState;
};

#endif