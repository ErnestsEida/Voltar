#ifndef COOKIE_ENGINE_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class CookieEngine
{
private:
  RenderWindow window;

public:
  CookieEngine();

  void start();
};

#endif