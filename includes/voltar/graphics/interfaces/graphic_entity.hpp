#ifndef VOLTAR_GRAPHICS_INTERFACES_GRAPHIC_ENTITY_HPP
#define VOLTAR_GRAPHICS_INTERFACES_GRAPHIC_ENTITY_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

using namespace sf;

namespace Voltar
{
  namespace Graphics
  {
    namespace Interfaces
    {
      class GraphicEntity
      {
      public:
        Transformable *as_transformable = nullptr;
        Drawable *as_drawable = nullptr;
        void *target = nullptr;

        GraphicEntity(void *target);
      };
    };
  };
};

#endif