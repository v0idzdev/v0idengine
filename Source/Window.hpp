#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>

namespace v0id {

/// @brief Represents the display window and draws drawables on it
class Window
{
public:
  /// @brief Create a new Window
  /// @param name The title of the window
  Window(const std::string& name);
  ~Window();

  /// @brief Update the state of the window on each frame
  void update();

  /// @brief Execute pre-draw code
  void beginDraw();

  /// @brief Draw drawables on the display window
  /// @param drawable The drawables
  void draw(const sf::Drawable& drawable);

  /// @brief Execute post-draw code
  void endDraw();

  /// @brief Get the coordinates of the centre of the window
  /// @return The coordinates
  sf::Vector2u getCentre() const;

  /// @brief Determine whether the window is currently open
  /// @return True if the window is open
  bool isOpen() const;

private:
  sf::RenderWindow window;
};

}

#endif