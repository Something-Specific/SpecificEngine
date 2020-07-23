#pragma once

#include <entt/entt.hpp>
#include "../Graphics/Renderer.h"

namespace Gin::ECS::Systems
{
    void RenderSystem(Graphics::Renderer *renderer, entt::registry &registry);
}