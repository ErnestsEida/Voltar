#include <voltar/graphics/interfaces/graphic_entity.hpp>

Voltar::Graphics::Interfaces::GraphicEntity::GraphicEntity(void *target)
{
  this->target = target;
  this->as_drawable = static_cast<Drawable *>(target);
  this->as_transformable = static_cast<Transformable *>(target);
}