#include "InputSystem.h"
#include "../Inputs/Action.hpp"
#include "../Inputs/InputType.hpp"
#include "../Inputs/Keys.h"

namespace Gin::ECS::Systems
{
    void InputSystem(entt::registry &registry, Inputs::Processor &input)
    {
        
        auto inputs = registry.view<Components::Input>();

        // Check the input for each action registered
        for(auto action : input.RegisteredActions) {
            auto inputKey = action.Value;
            short value = 0;

            // Read the physical input value
            auto inputType = action.Type;
            switch(inputType) {
                case Inputs::KEYBOARD: {
                    auto result = input.KeyboardState->IsKeyDown(static_cast<Inputs::Keys::Keys>(action.ID));
                    value = result ? SHRT_MAX : 0;
                }
                break;
                case Inputs::MOUSE:
                    CORE_WARN("Input action registered for an unhandled InputType: MOUSE");
                break;
                case Inputs::GAMEPAD:
                    CORE_WARN("Input action registered for an unhandled InputType: GAMEPAD");
                break;
                default:
                    CORE_WARN("Input action registered for an unhandled InputType: UNKNOWN");
                    continue;
            };


            // Update all of the input components with the new value
            for(auto entity : inputs) {
                auto inputComponent = inputs.get(entity);
                inputComponent.Actions[action.Name] = value;
            }
        }
    };
} // namespace Gin::ECS::Systems