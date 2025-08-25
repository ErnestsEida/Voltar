#ifndef VOLTAR_INTERNAL_SCENE_MANAGER_HPP
#define VOLTAR_INTERNAL_SCENE_MANAGER_HPP

#include <voltar/core/Scene.hpp>
#include <string>
#include <map>

typedef map<string, Voltar::Scene *> SceneMapping;

namespace Voltar
{
  namespace Internal
  {
    class SceneManager
    {
    private:
      static SceneMapping scene_mapping;
      static bool is_mapping_set;

      // Current loaded scene
      Scene *loaded_scene = nullptr;
      // Points to the holder within Voltar::Core, and will be used to store persitant objects.
      vector<Instance *> *instance_holder = nullptr;

    public:
      /**
       * [USE ONCE] [Required]
       * Set mapping once, with objects of scenes that are going to be used within the game.
       */
      static void set_scene_mapping(SceneMapping mapping);

      SceneManager();
      SceneManager(vector<Instance *> *instance_holder_ptr);

      /**
       * [PUBLIC]
       * Use this method to change scenes for your game.
       */
      vector<Instance *> load_scene(string scene_name);
    };
  };
};

#endif