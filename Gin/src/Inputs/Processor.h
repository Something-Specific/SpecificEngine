#pragma once

#include "..\GinPch.h"

#include "Controller.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Action.hpp"

namespace Gin
{
	namespace Inputs
	{
		class Processor
		{
		public:
			Controller *ControllerState;
			Keyboard *KeyboardState;
			Mouse *MouseState;
			std::vector<Action> RegisteredActions;

			Processor(GLFWwindow *window);
			~Processor();
		};
	} // namespace Inputs
} // namespace Gin
