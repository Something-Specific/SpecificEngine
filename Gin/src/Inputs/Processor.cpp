
#include "..\GinPch.h"
#include "Processor.h"

namespace Gin
{
	namespace Inputs
	{
		Processor::Processor(GLFWwindow *window)
		{
			KeyboardState = new Keyboard();
			glfwSetWindowUserPointer(window, this);
			glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mode) {
				// Here we retrieve the pointer we setted before. It will be equal to `this`
				auto& self = *static_cast<Processor*>(glfwGetWindowUserPointer(window));
				self.KeyboardState->UpdateState(key, action);
				CORE_TRACE("Key event: {0} - {1}", key, action);
			});
		}


		Processor::~Processor()
		{

		}


	}
}