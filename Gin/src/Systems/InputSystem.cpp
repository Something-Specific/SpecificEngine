#include "InputSystem.h"

namespace Gin::ECS::Systems
{
    void InputSystem(entt::registry &registry, Inputs::Processor &input)
    {
        auto controllable = registry.view<Components::Input, Components::Transform>();
        for (auto entity : controllable)
        {
            auto &transform = controllable.get<Components::Transform>(entity);

            if (input.KeyboardState->IsKeyDown(Inputs::Keys::W))
            {
                transform.Position.y -= 1;
            }

            if (input.KeyboardState->IsKeyDown(Inputs::Keys::S))
            {
                transform.Position.y += 1;
            }

            if (input.KeyboardState->IsKeyDown(Inputs::Keys::D))
            {
                transform.Position.x += 1;
            }

            if (input.KeyboardState->IsKeyDown(Inputs::Keys::A))
            {
                transform.Position.x -= 1;
            }
        }
    };
} // namespace Gin::ECS::Systems