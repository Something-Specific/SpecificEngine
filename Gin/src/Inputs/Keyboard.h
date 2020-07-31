#pragma once

#include "..\GinPch.h"

namespace Gin
{
	namespace Inputs
	{
		class Keyboard
		{
		public:
			Keyboard();
			~Keyboard();

			bool IsKeyDown(Keys::Keys key);

			void UpdateState(int key, int action);

		private:
			bool *KeyStates;
		};
	} // namespace Inputs
} // namespace Gin