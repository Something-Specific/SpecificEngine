#pragma once

#include "..\GinPch.h"
#include <glm/glm.hpp>

namespace Gin::ECS::Components
{
    struct Body
    {
        glm::vec2 Size;

        Body() = default;
        Body(const Body &) = default;
        Body(const glm::vec2 &size)
            : Size(size) {}
    };

} // namespace Gin::ECS::Components