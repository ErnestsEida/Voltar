#ifndef VOLTAR_CORE_HPP
#define VOLTAR_CORE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include <voltar/internal/scene_manager.hpp>
#include <voltar/internal/instance_manager.hpp>
#include <voltar/internal/window_manager.hpp>

using namespace sf;
using namespace std;

namespace Voltar
{
  class Core
  {
  private:
    const string MAIN_SCENE_KEY = "main";

    /* Window persistance attributes */
    int window_framerate;
    string window_title;

    Clock sf_clock; // Use SFML clock to calculate deltaTime
    RenderWindow window;

    vector<Voltar::Instance *> instances;
    Voltar::Internal::SceneManager scene_manager;
    Voltar::Internal::InstanceManager instance_manager;
    Voltar::Internal::WindowManager window_manager;

    void initialize_managers();

    /**
     * Assigns value to the static singleton variable.
     * Used within Voltar::Core constructors.
     */
    void assign_singleton(Voltar::Core *instance);

    /**
     * Called within `start()` and runs single time before entering the engine mainloop
     */
    void boot_sequence();

  public:
    /**
     * Singeton to be used within the game code, to call Core engine functions or access its module managers.
     */
    static Voltar::Core *singleton;
    /**
     * Time between frame renders.
     * Use with calculations to reduce dependency on framerate.
     */
    static float deltaTime;

    /**
     * Takes initial window parameters and uses them to create the main RenderWindow instance
     */
    Core(string window_title = "Main Window", Vector2u window_size = {1280, 720}, bool fullscreen = false, int framerate = 60, ContextSettings opengl_settings = ContextSettings());

    /**
     * Set fullscreen state for current window
     * @param enabled fullscreen is enabled or not
     */
    void window_set_fullscreen(bool enabled);

    /**
     * Starts execution of the engine.
     */
    void start();
  };
};

#endif