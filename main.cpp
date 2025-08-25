#include <SFML/Graphics.hpp>
#include <voltar/core.hpp>

using namespace sf;

class TemplateScene : public Voltar::Scene
{
  vector<Voltar::Instance *> build_scene_instances()
  {
    return vector<Voltar::Instance *>{
        new Voltar::Instance(),
        new Voltar::Instance(),
        new Voltar::Instance(),
        new Voltar::Instance(),
        new Voltar::Instance(),
        new Voltar::Instance(),
        new Voltar::Instance(),
        new Voltar::Instance(),
    };
  }
};

int main()
{
  Voltar::Core e("Template Window", {1280, 720}, false, 144);
  Voltar::Internal::SceneManager::set_scene_mapping({{"main", new TemplateScene()}});

  e.start();
}