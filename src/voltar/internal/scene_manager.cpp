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

void Voltar::Internal::SceneManager::load_scene(string scene_name)
{
  for (Instance *t_instance : *this->instance_holder)
  {
    t_instance->before_unload();
  }

  if (this->loaded_scene != nullptr && this->loaded_scene->get_persistant())
  {
    this->loaded_scene->persisted_instances = *this->instance_holder;
  }
  else
  {
    for (Instance *t_inst : *this->instance_holder)
    {
      delete (t_inst);
    }

    this->instance_holder->clear();
    this->instance_holder->shrink_to_fit();
  }

  try
  {
    Scene *target_scene = scene_mapping.at(scene_name);
    this->loaded_scene = target_scene;

    *this->instance_holder = this->loaded_scene->get_scene_instances();

    for (Instance *inst : *this->instance_holder)
    {
      inst->after_create();
    }
  }
  catch (out_of_range &e)
  {
    Logger::Error("Scene '" + scene_name + "' not defined in the scene mapping");
  }
}