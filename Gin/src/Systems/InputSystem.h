#pragma once

#include <entt/entt.hpp>
#include "../Components/Input.hpp"
#include "../Inputs/Processor.h"

namespace Gin::ECS::Systems
{
    void InputSystem(entt::registry &registry, Inputs::Processor &inputProcessor);
} // namespace Gin::ECS::Systems