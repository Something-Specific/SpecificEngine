#pragma once

#include <entt/entt.hpp>
#include "../Components/Input.hpp"
#include "../Components/Transform.hpp"
#include "../Inputs/Processor.h"
#include "../Inputs/Keys.h"

namespace Gin::ECS::Systems
{
    void InputSystem(entt::registry &registry, Inputs::Processor &input);
} // namespace Gin::ECS::Systems