#pragma once

#include <entt/entt.hpp>
#include "../Components/Body.hpp"
#include "../Components/Collider.hpp"
#include "../Components/Transform.hpp"

namespace Gin::ECS::Systems
{
    void InputSystem(entt::registry &registry);
} // namespace Gin::ECS::Systems