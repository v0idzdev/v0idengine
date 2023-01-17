#ifndef SCENELEVEL_HPP
#define SCENELEVEL_HPP

#include "Input.hpp"
#include "ResourcePath.hpp" // WorkingDirectory
#include "Scene.hpp"

class SceneLevel : public Scene
{
public:
  SceneLevel(ResourcePath& resourcePath);
  ~SceneLevel();

  void onCreate() override;
  void onDestroy() override;
  void processInput() override;
  void update(float deltaTime) override;
  void draw(Window& window) override;

private:
  // TODO: Place sprites and scene variables here

  ResourcePath& resourcePath;
  Input input;
};

#endif