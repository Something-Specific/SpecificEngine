#pragma once

#include <entt/entt.hpp>
#include "../Graphics/Renderer.h"

namespace Gin::ECS::Systems
{
    void RenderSystem(entt::registry &registry, Graphics::Renderer &renderer);
}