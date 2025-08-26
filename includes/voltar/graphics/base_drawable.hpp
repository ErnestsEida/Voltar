#ifndef VOLTAR_GRAPHICS_BASE_DRAWABLE_HPP
#define VOLTAR_GRAPHICS_BASE_DRAWABLE_HPP

#include <voltar/core/instance.hpp>
#include <vector>
#include <SFML/Graphics/Drawable.hpp>

using namespace sf;
using namespace std;

namespace Voltar
{
  namespace Graphics
  {
    class BaseDrawable : public Voltar::Instance
    {
    private:
      vector<Drawable *> drawables;

    public:
      /**
       * [INTERNAL] [OVERRIDE] [Required]
       * Return vector is then appended to drawables pipeline that should currently be drawn on screen.
       * default `this->before_unload` should take care of removing these drawables from the drawable pipeline.
       */
      virtual vector<Drawable *> assign_drawables() = 0;

      void after_create() override final;
      void before_unload() override final;
    };
  };
};

#endif