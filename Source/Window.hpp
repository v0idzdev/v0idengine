#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SFML/Graphics.hpp>

namespace vm {

class Window
{
public:
  Window(const std::string& windowName);

  void update();
  void beginDraw();
  void draw(const sf::Drawable& drawable);
  void endDraw();
  bool isOpen() const;

private:
  sf::RenderWindow window;
};

}; // namespace vm

#endif