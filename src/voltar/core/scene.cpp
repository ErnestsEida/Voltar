#include <voltar/core/Scene.hpp>
#include <voltar/logger.hpp>

using namespace Voltar;

Scene::Scene(bool persistant) : persistant(persistant) {}

vector<Instance *> Scene::get_scene_instances()
{
  if (this->persistant && !this->persisted_instances.empty())
  {
    return this->persisted_instances;
  }
  else
  {
    // Clear incase persisted objects are still present, and scene is no longer persistant
    this->persisted_instances.clear();
    this->persisted_instances.shrink_to_fit();
    this->persisted_instances = vector<Instance *>();

    return this->build_scene_instances();
  }
}

void Scene::set_persitant(bool persitant)
{
  this->persistant = persistant;
}

bool Scene::get_persistant() const
{
  return this->persistant;
}