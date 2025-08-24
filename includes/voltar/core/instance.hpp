#ifndef VOLTAR_CORE_INSTANCE_HPP
#define VOLTAR_CORE_INSTANCE_HPP

namespace Voltar
{
  class Instance
  {
  public:
    Instance();

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
  };
};

#endif