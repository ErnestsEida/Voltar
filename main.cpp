#include <SFML/Graphics.hpp>
#include "cookie_engine.hpp"

using namespace sf;

int main()
{
  CookieEngine *engine = new CookieEngine();
  engine->start();
}