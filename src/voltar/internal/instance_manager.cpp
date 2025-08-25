#include <voltar/internal/instance_manager.hpp>

Voltar::Internal::InstanceManager::InstanceManager() {}

Voltar::Internal::InstanceManager::InstanceManager(vector<Voltar::Instance *> *instance_holder_ptr)
{
  this->instance_holder = instance_holder_ptr;
}