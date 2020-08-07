#include "PhysicsSystem.h"

namespace Gin::ECS::Systems
{
    void InputSystem(entt::registry &registry)
    {
        auto physical = registry.view<Components::Transform, Components::Body, Components::Collider>();
        for (auto entity : physical)
        {
            auto [transform, body, collider] = physical.get<Components::Transform, Components::Body, Components::Collider>(entity);

            if (body.Velocity.x || body.Velocity.y)
            {
                glm::vec2 newPos = transform.Position + body.Velocity;
                for (auto other : physical)
                {
                                }
            }
        }
    };
} // namespace Gin::ECS::Systems