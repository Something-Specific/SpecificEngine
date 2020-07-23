#pragma once

#include <entt/entt.hpp>

#include "..\GinPch.h"
#include "..\Graphics\Renderer.h"
#include "..\Inputs\Processor.h"

namespace Gin::Core
{
    class Scene
    {
    public:
        Scene();
        ~Scene();

        entt::registry &getRegistry();

        void Scene::Update(Inputs::Processor *processor, float dt);
        void Scene::Render(Graphics::Renderer *renderer, float dt);

    private:
        entt::registry registry;
    };
} // namespace Gin::Core
