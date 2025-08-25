#include <voltar/core/Instance.hpp>
#include <chrono>

string generate_uuid(string prefix = "")
{
  uint64_t millisec = chrono::system_clock::now().time_since_epoch().count();
  string timeAsString = to_string(millisec);
  return prefix + timeAsString;
}

Voltar::Instance::Instance(Voltar::Instance *parent, float x, float y, int z, string tag, string instance_name)
    : parent(parent), x(x), y(y), z(z), tag(tag), id(generate_uuid(instance_name)) {}

void Voltar::Instance::add_child(Voltar::Instance *child)
{
  child->parent = this;
  this->children.push_back(child);
}

Voltar::Instance::~Instance()
{
}