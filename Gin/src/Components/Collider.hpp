#pragma once

#include "..\GinPch.h"
#include <glm/glm.hpp>

namespace Gin::ECS::Components
{
    constexpr byte CIRCLE_TYPE = 1;
    constexpr byte BOX_TYPE = 2;

    struct Collider
    {
        byte Type;
        virtual ~Collider() {};
    };
    struct CircleCollider : Collider
    {
        float Radius;

        CircleCollider() {
            Type = CIRCLE_TYPE;
        };
        CircleCollider(const CircleCollider &) = default;
        CircleCollider(const float &radius)
            : Radius(radius) {}
    };
    struct BoxCollider : Collider
    {
        glm::vec2 Size;

        BoxCollider() {
            Type = BOX_TYPE;
        };
        BoxCollider(const BoxCollider &) = default;
        BoxCollider(const glm::vec2 &size)
            : Size(size) {}
    };

} // namespace Gin::ECS::Components