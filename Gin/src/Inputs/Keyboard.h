#pragma once

#include "..\GinPch.h"

namespace Gin
{
	namespace Inputs
	{
		class  Keyboard
		{
		public:
			Keyboard();
			~Keyboard();

			void UpdateState(int key, int action);

		};
	}
}
