#ifndef C_Transform_hpp
#define C_Transform_hpp

#include "Component.hpp"

namespace v0id::component {

/// @brief Stores and modifies the position, rotation, and scale of an Object
/// @note Every Object will have a Transform added to it by default
class Transform : public Component
{
public:
  /// @brief Create a new Transform
  /// @param owner The Object to add the component to
  Transform(Object* owner);

  /// @brief Set the position of the Object
  /// @param x The new x position
  /// @param y The new y position
  void setPosition(float x, float y);

  /// @brief Set the position of the Object
  /// @param pos The new position
  void setPosition(const sf::Vector2f& pos);

  /// @brief Increment the position of the Object
  /// @param x The value to increment the x position by
  /// @param y The value to increment the y position by
  void addPosition(float x, float y);

  /// @brief Increment the position of the Object
  /// @param pos The value to increment the position by
  void addPosition(sf::Vector2f pos);

  /// @brief Set the x position of the Object
  /// @param x The new x position
  void setX(float x);

  /// @brief Set the y position of the Object
  /// @param y The new y position
  void setY(float y);

  /// @brief Increment the x position of the Object
  /// @param x The value to increment the x position by
  void addX(float x);

  /// @brief Increment the y position of the Object
  /// @param y The value to increment the y position by
  void addY(float y);

  /// @brief Set the scale of the Object
  /// @param x The new x scale
  /// @param y The new y scale
  void setScale(float x, float y);

  /// @brief Set the scale of the Object
  /// @param scale The new scale
  void setScale(const sf::Vector2f& scale);

  /// @brief Set the x scale of the Object
  /// @param x The new x scale
  void setScaleX(float x);

  /// @brief Set the y scale of the Object
  /// @param y The new y scale
  void setScaleY(float y);

  /// @brief Set the rotation of the Object
  /// @param degrees The new rotation
  void setRotation(float degrees);

  /// @brief Increment the rotation of the Object
  /// @param degrees The value to increment the rotation by
  void addRotation(float degrees);

  /// @brief Get the position of the Object
  /// @return The position
  const sf::Vector2f& getPosition() const;

  /// @brief Get the scale of the Object
  /// @return The scale
  const sf::Vector2f& getScale() const;

  /// @brief Get the rotation of the object
  /// @return The rotation
  const float& getRotation() const;

private:
  sf::Vector2f position, scale;
  float rotation;
};

}

#endif