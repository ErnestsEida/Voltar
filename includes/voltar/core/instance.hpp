#ifndef VOLTAR_CORE_INSTANCE_HPP
#define VOLTAR_CORE_INSTANCE_HPP

#include <string>
#include <vector>

using namespace std;

namespace Voltar
{
  class Instance
  {
  private:
    vector<Instance *> children;

  public:
    Instance *parent = nullptr;
    string tag, id;
    float x, y;
    int z;

    /**
     * Default constructor
     * Set default coordinates, but be aware, that at this point, not all objects that have been defined in scene are created.
     *
     * So if you decide to set coordinates, perform raw calculations not depending on instance context in scene.
     *
     * [NOTE] if the instance is created in process of game(through `on_tick` or similar) - then referencing other objects is considered safe
     * @param parent Instance parent, if `nullptr` its at root level or is a hanging pointer and takes up memory :)
     * @param x, y Instance coordinates in world. (or offset value from parent, if parent is present)
     * @param z Drawing sequence. This is summed on top of parents `z` value (if parent is present)
     * @param tag Grouping similar instances.
     * @param instance_name ID prefix attribute (mainly used within internals, rarely exposed)
     */
    Instance(Instance *parent = nullptr, float x = 0, float y = 0, int z = 0, string tag = "", string instance_name = "instance");

    /**
     * Method for adding children to current object
     * @param child Instance pointer to be added as child
     */
    void add_child(Instance *child);

    /**
     * [OVERRIDE] [Optional]
     * Serves same function as constructor, but is run at moment, when all other objects are also present in game context.
     * Use this instead of the class constructor if you want to reference something within Game context (`Window`, `Scene`, `Instances`)
     */
    virtual void after_create() {};

    /**
     * [OVERRIDE] [Optional]
     * First instance method, executed on every tick.
     * Same functionality as `on_tick` or `after_tick`.
     */
    virtual void before_tick() {};

    /**
     * [OVERRIDE] [Optional]
     * First instance method, executed on every tick.
     * Same functionality as `before_tick` or `after_tick`.
     */
    virtual void on_tick() {};

    /**
     * [OVERRIDE] [Optional]
     * Last instance method, executed on every tick.
     * Same functionality as `on_tick` or `before_tick`.
     */
    virtual void after_tick() {};

    /**
     * [OVERRIDE] [Optional]
     * Executed before destroyed.
     * When a persistant `Scene` is changed from, the objects are not destroyed(aka destructor is not called)
     * So this can be used to perform some actions within game comtext, before the scene is unloaded and objects are stored away.
     */
    virtual void before_unload() {};

    virtual ~Instance();
  };
};

#endif