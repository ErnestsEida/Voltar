#include <SFML/Graphics.hpp>
#include <voltar/core.hpp>

using namespace sf;

int main()
{
  Voltar::Core e("Template Window", {1280, 720}, false, 144);
  e.start();
}