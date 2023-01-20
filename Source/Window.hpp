#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>

namespace v0id {

class Window
{
public:
  Window(const std::string& name);
  ~Window();

  void update();
  void beginDraw();
  void draw(const sf::Drawable& drawable);
  void endDraw();
  sf::Vector2u getCentre() const;
  bool isOpen() const;

private:
  sf::RenderWindow window;
};

}

#endif