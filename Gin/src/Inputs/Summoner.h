#pragma once

#include "Processor.h"

#include <gainput\gainput.h>

namespace Gin
{
	namespace Inputs
	{
		class Summoner
		{
		public:
			Processor *processor;

			Summoner(float width, float height);
			~Summoner();

			void Update();

		private:
			gainput::InputManager* manager;
			
		};
	}
}

