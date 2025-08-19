#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
  auto window = RenderWindow(VideoMode({1280, 720}), "CMake SFML Project");
  window.setFramerateLimit(144);

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