#ifndef VOLTAR_CORE_HPP
#define VOLTAR_CORE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

namespace Voltar
{
  class Core
  {
  private:
    /* Window persistance attributes */
    int window_framerate;
    string window_title;

    Clock sf_clock; // Use SFML clock to calculate deltaTime
    RenderWindow window;

    void assign_singleton(Voltar::Core *instance);

  public:
    static Voltar::Core *singleton;
    static float deltaTime;

    Core(string window_title = "Main Window", Vector2u window_size = {1280, 720}, bool fullscreen = false, int framerate = 60, ContextSettings opengl_settings = ContextSettings());

    /* Window methods */
    void window_set_fullscreen(bool enabled);

    void start();
  };
};

#endif