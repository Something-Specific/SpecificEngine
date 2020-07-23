#include "InputSystem.hpp"

namespace Gin::ECS::Systems
{
    void InputSystem(entt::registry &registry, Inputs::Processor &inputProcessor)
    {
        auto renderable = registry.view<Components::Input>();
        for (auto entity : renderable)
        {
            //auto [sprite, transform] = renderable.get<Components::Sprite, Components::Transform>(entity);
            //renderer.Render(sprite.Texture, transform.Position, transform.Rotation);


            //inputProcessor.
        }
    };
} // namespace Gin::ECS::Systems