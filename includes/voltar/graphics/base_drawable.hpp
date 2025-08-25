#ifndef VOLTAR_GRAPHICS_BASE_DRAWABLE_HPP
#define VOLTAR_GRAPHICS_BASE_DRAWABLE_HPP

#include <voltar/core/instance.hpp>

namespace Voltar
{
  namespace Graphics
  {
    class BaseDrawable : public Voltar::Instance
    {
    public:
      void after_tick() override final;
    };
  };
};

#endif