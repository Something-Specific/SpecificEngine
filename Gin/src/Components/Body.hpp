#pragma once

#include "..\GinPch.h"
#include <glm/glm.hpp>

namespace Gin::ECS::Components
{
    struct Body
    {
        glm::vec2 Velocity;

        Body() = default;
        Body(const Body &) = default;
        Body(const glm::vec2 &velocity)
            : Velocity(velocity) {}
    };

} // namespace Gin::ECS::Components