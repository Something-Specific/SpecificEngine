
#include "..\GinPch.h"
#include "Processor.h"

namespace Gin
{
	namespace Inputs
	{
		Processor::Processor(GLFWwindow *window)
		{
			KeyboardState = new Keyboard();
			MouseState = new Mouse();
			ControllerState = new Controller();

			glfwSetWindowUserPointer(window, this);
			glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scancode, int action, int mode) {
				auto &self = *static_cast<Processor *>(glfwGetWindowUserPointer(window));
				self.KeyboardState->UpdateState(key, action);
				// CORE_TRACE("Key event: {0} - {1}", key, action);
			});

			glfwFocusWindow(window);
		}

		Processor::~Processor()
		{
			delete KeyboardState;
			delete ControllerState;
			delete MouseState;
		}

	} // namespace Inputs
} // namespace Gin