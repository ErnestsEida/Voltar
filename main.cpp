#include <SFML/Graphics.hpp>
#include <voltar/core.hpp>
#include <voltar/logger.hpp>

using namespace sf;

int main()
{
  Voltar::Core *e = new Voltar::Core();
  e->start();
}