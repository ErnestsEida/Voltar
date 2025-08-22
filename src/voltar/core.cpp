#include <voltar/core.hpp>
#include <voltar/logger.hpp>

Voltar::Core *Voltar::Core::singleton = nullptr;
float Voltar::Core::deltaTime = 0.0f;

/**
 * Takes initial window parameters and uses them to create the main RenderWindow instance
 */
Voltar::Core::Core(string window_title, Vector2u window_size, bool fullscreen, int framerate, ContextSettings opengl_settings)
{
  this->window = RenderWindow(
      VideoMode(window_size),
      window_title,
      fullscreen ? State::Fullscreen : State::Windowed,
      opengl_settings);

  this->window.setFramerateLimit(framerate);
  this->window_framerate = framerate;
  this->window_title = window_title;

  this->assign_singleton(this);
}

/**
 * Assigns value to the static singleton variable.
 * Used within Voltar::Core constructors.
 */
void Voltar::Core::assign_singleton(Voltar::Core *instance)
{
  if (singleton == nullptr)
  {
    Voltar::Core::singleton = instance;
  }
  else
  {
    Voltar::Logger::Error("Cannot run 2 instances of the engine at the same time");
  }
}

/**
 * Set fullscreen state for current window
 * @param enabled whether fullscreen is enabled or not
 */
void Voltar::Core::window_set_fullscreen(bool enabled)
{
  this->window = RenderWindow(
      VideoMode(this->window.getSize()),
      this->window_title,
      enabled ? State::Fullscreen : State::Windowed,
      this->window.getSettings());
}

/**
 * Starts execution of the engine.
 */
void Voltar::Core::start()
{
  while (window.isOpen())
  {
    while (const std::optional event = window.pollEvent())
    {
      Voltar::Core::deltaTime = this->sf_clock.restart().asSeconds();

      if (event->is<Event::Closed>())
      {
        window.close();
      }
    }

    window.clear();
    window.display();
  }
}