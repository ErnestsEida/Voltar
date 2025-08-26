#include <voltar/core.hpp>
#include <voltar/logger.hpp>

Voltar::Core *Voltar::Core::singleton = nullptr;
float Voltar::Core::deltaTime = 0.0f;

void Voltar::Core::initialize_managers()
{
  this->scene_manager = Voltar::Internal::SceneManager(&this->instances);
  this->instance_manager = Voltar::Internal::InstanceManager(&this->instances);
}

Voltar::Core::Core(string window_title, Vector2u window_size, bool fullscreen, int framerate, ContextSettings opengl_settings)
{
  this->initialize_managers();

  // TODO: Replace with `WindowManager`
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

void Voltar::Core::window_set_fullscreen(bool enabled)
{
  this->window = RenderWindow(
      VideoMode(this->window.getSize()),
      this->window_title,
      enabled ? State::Fullscreen : State::Windowed,
      this->window.getSettings());
}

void Voltar::Core::boot_sequence()
{
  this->scene_manager.load_scene(MAIN_SCENE_KEY);
}

void Voltar::Core::start()
{
  this->boot_sequence();

  while (window.isOpen())
  {
    // Setting deltaTime
    Voltar::Core::deltaTime = this->sf_clock.restart().asSeconds();

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