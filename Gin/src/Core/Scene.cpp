#include "Scene.h"
#include "..\Systems\RenderSystem.h"
#include "..\Systems\InputSystem.h"

namespace Gin::Core
{

    Scene::Scene() {}

    Scene::~Scene() {}

    entt::registry &Scene::getRegistry()
    {
        return registry;
    }

    void Scene::Update(Inputs::Processor *processor, float dt)
    {
        ECS::Systems::InputSystem(registry, *processor);
    }

    void Scene::Render(Graphics::Renderer *renderer, float dt)
    {
        ECS::Systems::RenderSystem(registry, *renderer);
    }
} // namespace Gin::Core
