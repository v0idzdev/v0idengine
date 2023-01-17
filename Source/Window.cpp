#include "Window.hpp"

Window::Window(const std::string& windowName)
  : window(sf::VideoMode(800, 600), windowName, sf::Style::Titlebar)
{
  window.setVerticalSyncEnabled(true);
}

Window::~Window() {}

void
Window::update()
{
  sf::Event event;

  if (window.pollEvent(event))
    if (event.type == sf::Event::Closed)
      window.close();
}

void
Window::beginDraw()
{
  window.clear(sf::Color::White);
}

void
Window::draw(const sf::Drawable& drawable)
{
  window.draw(drawable);
}

void
Window::endDraw()
{
  window.display();
}

sf::Vector2u
Window::getCentre() const
{
  sf::Vector2u size = window.getSize();
  return sf::Vector2u(size.x / 2, size.y / 2);
}

bool
Window::isOpen() const
{
  return window.isOpen();
}