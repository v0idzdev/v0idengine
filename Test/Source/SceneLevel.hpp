#ifndef SCENELEVEL_HPP
#define SCENELEVEL_HPP

#include <v0idengine/Input.hpp>
#include <v0idengine/ResourcePath.hpp>
#include <v0idengine/Scene.hpp>

class SceneLevel : public v0id::Scene
{
public:
  SceneLevel(v0id::ResourcePath& resourcePath);
  ~SceneLevel();

  void onCreate() override;
  void onDestroy() override;
  void processInput() override;
  void update(float deltaTime) override;
  void draw(v0id::Window& window) override;

private:
  // TODO: Place sprites and scene variables here

  v0id::ResourcePath& resourcePath;
  v0id::Input input;
};

#endif