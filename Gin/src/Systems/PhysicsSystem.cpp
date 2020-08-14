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
                bool collided = false;
                glm::vec2 oldPos = transform.Position;
                transform.Position += body.Velocity;
                for (auto other : physical)
                {
                    auto [oTransform, oCollider] = physical.get<Components::Transform, Components::Collider>(other);
                    if (Math::IsColliding(transform, collider, oTransform, oCollider))
                    {
                        collided = true;
                        break;
                    }
                }
                if (collided)
                {
                    transform.Position = oldPos;
                }
            }
        }
    };
} // namespace Gin::ECS::Systems