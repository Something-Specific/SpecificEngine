
#ifndef  PROCESSOR_H
#define PROCESSOR_H

#include <GLFW\glfw3.h>

#include "Controller.h"
#include "Keyboard.h"
#include "Mouse.h"

namespace Core
{
	namespace Inputs
	{
		class Processor
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

#endif // ! PROCESSOR_H
