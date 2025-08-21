#include <voltar/core.hpp>
#include <voltar/logger.hpp>

Voltar::Core *Voltar::Core::singleton = nullptr;

Voltar::Core::Core()
{
  this->window = RenderWindow(VideoMode({1920, 1080}), "Voltar template window");
  this->window.setFramerateLimit(144);
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

void Voltar::Core::start()
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