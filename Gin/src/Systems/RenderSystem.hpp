#pragma once

#include <entt/entt.hpp>
#include "../Components/Transform.hpp"
#include "../Components/Sprite.hpp"
#include "../Graphics/Renderer.h"

namespace Gin::ECS::Systems
{
    void RenderSystem(Graphics::Renderer &renderer, entt::registry &registry)
    {
        auto renderable = registry.view<Components::Sprite, Components::Transform>();
        for (auto entity : renderable)
        {
            auto [sprite, transform] = renderable.get<Components::Sprite, Components::Transform>(entity);
            renderer.Render(sprite.Texture, transform.Position, transform.Rotation);
        }
    }
} // namespace Gin::ECS::Systems