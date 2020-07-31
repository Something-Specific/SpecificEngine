
#include "..\GinPch.h"
#include "Keyboard.h"

namespace Gin
{
	namespace Inputs
	{
		Keyboard::Keyboard()
		{
			KeyStates = new bool[1024];
		}

		void Keyboard::UpdateState(int key, int action)
		{
			KeyStates[key] = action;
		}

		bool Keyboard::IsKeyDown(Keys::Keys key)
		{
			return KeyStates[key];
		}

		Keyboard::~Keyboard()
		{
			delete KeyStates;
		}
	} // namespace Inputs
} // namespace Gin