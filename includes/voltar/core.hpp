#ifndef VOLTAR_CORE_HPP
#define VOLTAR_CORE_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

namespace Voltar
{
  class Core
  {
  private:
    RenderWindow window;

    void assign_singleton(Voltar::Core *instance);

  public:
    static Voltar::Core *singleton;

    Core();
    void start();
  };
};

#endif