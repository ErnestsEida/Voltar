#include <voltar/graphics/base_drawable.hpp>

void Voltar::Graphics::BaseDrawable::after_create()
{
  this->drawables = this->assign_drawables();
  // TODO: Append to global drawables pipeline
}

void Voltar::Graphics::BaseDrawable::before_unload()
{
  for (Drawable *drawable_ptr : this->drawables)
  {
    delete (drawable_ptr);
  }

  this->drawables.clear();
  this->drawables.shrink_to_fit();
}