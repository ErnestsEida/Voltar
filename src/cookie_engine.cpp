#include "cookie_engine.hpp"

CookieEngine::CookieEngine()
{
  this->window = RenderWindow(VideoMode({1920, 1080}), "CookieEngine Window");
  this->window.setFramerateLimit(144);
}

void CookieEngine::start()
{
  while (window.isOpen())
  {
    while (const std::optional event = window.pollEvent())
    {
      if (event->is<Event::Closed>())
      {
        window.close();
      }
    }

    window.clear();
    window.display();
  }
}