#pragma once

#include "..\GinPch.h"
#include <glm/glm.hpp>

namespace Gin
{
    namespace ECS
    {
        namespace Components
        {
            struct Body
            {
                glm::vec2 Size;

                Body() = default;
                Body(const Body &) = default;
                Body(const glm::vec2 &size)
                    : Size(size) {}
            };

        } // namespace Components

    } // namespace ECS

} // namespace Gin