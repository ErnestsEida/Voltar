#ifndef VOLTAR_INTERNAL_INSTANCE_MANAGER_HPP
#define VOLTAR_INTERNAL_INSTANCE_MANAGER_HPP

#include <vector>
#include <voltar/core/instance.hpp>

using namespace std;

namespace Voltar
{
  namespace Internal
  {
    class InstanceManager
    {
    private:
      vector<Voltar::Instance *> *instance_holder = nullptr;

    public:
      InstanceManager();
      InstanceManager(vector<Voltar::Instance *> *instance_holder_ptr);
    };
  };
};

#endif