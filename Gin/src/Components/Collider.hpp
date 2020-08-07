#pragma once

#include "..\GinPch.h"
#include <glm/glm.hpp>

namespace Gin::ECS::Components
{
    struct Collider
    {

        virtual ~Collider(){};
    };
    struct CircleCollider : Collider
    {
        float Radius;

        CircleCollider() = default;
        CircleCollider(const CircleCollider &) = default;
        CircleCollider(const float &radius)
            : Radius(radius) {}
    };
    struct BoxCollider : Collider
    {
        glm::vec2 Size;

        BoxCollider() = default;
        BoxCollider(const BoxCollider &) = default;
        BoxCollider(const glm::vec2 &size)
            : Size(size) {}
    };

} // namespace Gin::ECS::Components