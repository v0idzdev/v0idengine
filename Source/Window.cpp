#include "Window.hpp"

vm::Window::Window(const std::string& windowName)
  : window(sf::VideoMode(800, 600), windowName, sf::Style::Titlebar)
{
  window.setVerticalSyncEnabled(true);
}

void
vm::Window::update()
{
  sf::Event event;

  if (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }
}

void
vm::Window::beginDraw()
{
  window.clear(sf::Color::White);
}

void
vm::Window::draw(const sf::Drawable& drawable)
{
  window.draw(drawable);
}

void
vm::Window::endDraw()
{
  window.display();
}

bool
vm::Window::isOpen() const
{
  return window.isOpen();
}