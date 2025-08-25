#include <voltar/internal/scene_manager.hpp>
#include <voltar/logger.hpp>

bool Voltar::Internal::SceneManager::is_mapping_set = false;
SceneMapping Voltar::Internal::SceneManager::scene_mapping = SceneMapping();

void Voltar::Internal::SceneManager::set_scene_mapping(SceneMapping mapping)
{
  if (Voltar::Internal::SceneManager::is_mapping_set)
  {
    Logger::Error("Do not set the scene mapping more than once!");
  }

  Voltar::Internal::SceneManager::scene_mapping = mapping;
  Voltar::Internal::SceneManager::is_mapping_set = true;
}

Voltar::Internal::SceneManager::SceneManager() {}

Voltar::Internal::SceneManager::SceneManager(vector<Voltar::Instance *> *instance_holder_ptr)
{
  this->instance_holder = instance_holder_ptr;
}

vector<Voltar::Instance *> Voltar::Internal::SceneManager::load_scene(string scene_name)
{
  if (this->loaded_scene != nullptr && this->loaded_scene->get_persistant())
  {
    this->loaded_scene->persisted_instances = *this->instance_holder;
  }

  try
  {
    Scene *target_scene = scene_mapping.at(scene_name);
    this->loaded_scene = target_scene;
    return this->loaded_scene->get_scene_instances();
  }
  catch (out_of_range &e)
  {
    Logger::Error("Scene '" + scene_name + "' not defined in the scene mapping");
    return vector<Voltar::Instance *>();
  }
}