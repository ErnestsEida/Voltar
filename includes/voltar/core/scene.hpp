#ifndef VOLTAR_CORE_SCENE_HPP
#define VOLTAR_CORE_SCENE_HPP

#include <voltar/core/Instance.hpp>
#include <vector>

using namespace std;

namespace Voltar
{
  class Scene
  {
  private:
    // Whether object should be re-initialized on scene load or not. (true == not re-initialized)
    bool persistant = false;

  public:
    vector<Instance *> persisted_instances;

    Scene();

    /**
     * [INTERNAL]
     * Dynamic method for returning the actual context of Instance vectors.
     * - Persistant     => returns stored persisted instances vector without running the `build_scene_instances`, unless persisted instances are empty, then `build_scene_instances` is ran
     * - Non-persistant => runs `build_scene_instances` and returns the resulting vector. (if persisted instances are present, they are destroyed)
     */
    virtual vector<Instance *> get_scene_instances() final;

    /**
     * [OVERRIDE] [Required]
     * Virtual function, responsible for initializing all scene scene objects (that have to be there at time of scene creation).
     */
    virtual vector<Instance *> build_scene_instances() = 0;

    /**
     * [PUBLIC]
     * Sets the persitant flag for the scene.
     * If persitant, the Instance objects won't be destroyed when changing to another scene, and stored for next load.
     * Otherwise, the objects are destroyed and re-built when the scene is loaded the next time.
     */
    void set_persitant(bool persistant);

    /**
     * Returns the persitant flag value for the scene.
     */
    bool get_persistant() const;
  };
};

#endif