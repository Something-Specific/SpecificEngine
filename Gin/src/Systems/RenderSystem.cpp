#pragma once

#include "RenderSystem.h"
#include "../Components/Transform.hpp"
#include "../Components/Sprite.hpp"
#include "../Utils/Log.h"

namespace Gin::ECS::Systems
{
    void RenderSystem(entt::registry &registry, Graphics::Renderer &renderer)
    {
        auto renderable = registry.view<Components::Sprite, Components::Transform>();
        for (auto entity : renderable)
        {
            auto [sprite, transform] = renderable.get<Components::Sprite, Components::Transform>(entity);
            renderer.Render(sprite.Texture, transform.Position, transform.Rotation);
        }
    }
} // namespace Gin::ECS::Systems