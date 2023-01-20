#ifndef SCENELEVEL_HPP
#define SCENELEVEL_HPP

#include "CarMovement.hpp"
#include <v0idengine/Input.hpp>
#include <v0idengine/Object.hpp>
#include <v0idengine/ResourcePath.hpp>
#include <v0idengine/Scene.hpp>
#include <v0idengine/Sprite.hpp>

class SceneLevel : public v0id::Scene
{
public:
  SceneLevel(v0id::ResourcePath& resourcePath);
  ~SceneLevel();

  void onCreate() override;
  void onDestroy() override;
  void processInput() override;
  void update(float deltaTime) override;
  void lateUpdate(float deltaTime) override;
  void draw(v0id::Window& window) override;

private:
  // TODO: Place sprites and scene variables here

  // Create player
  std::shared_ptr<v0id::Object> player;

  v0id::ResourcePath& resourcePath;
  v0id::Input input;
};

#endif