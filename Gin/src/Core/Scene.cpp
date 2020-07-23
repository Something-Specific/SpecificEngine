#include "Scene.h";

#include "..\Systems\RenderSystem.hpp"

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
    }

    void Scene::Render(Graphics::Renderer *renderer, float dt)
    {
        ECS::Systems::RenderSystem(renderer, getRegistry());
    }
} // namespace Gin::Core
