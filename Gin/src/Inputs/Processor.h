#pragma once

#include "..\GinPch.h"

#include "Controller.h"
#include "Keyboard.h"
#include "Mouse.h"

namespace Gin
{
	namespace Inputs
	{
		class  Processor
		{
		public:
			Controller *ControllerState;
			Keyboard *KeyboardState;
			Mouse *MouseState;

			Processor(GLFWwindow *window);
			~Processor();

		};
	}
}
