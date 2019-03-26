#pragma once

#include "Processor.h"


//TODO: should be moved to project settings or macro file.
#define GAINPUT_DEBUG
#define GAINPUT_PLATFORM_WIN

#include <gainput\gainput.h>

namespace Gin
{
	namespace Inputs
	{
		enum Buttons {
			Primary,
			Secondary
		};

		class Summoner
		{
		public:
			Processor *processor;

			Summoner(float width, float height);
			~Summoner();

			void Update();

		private:
			gainput::InputManager* manager;
			gainput::InputMap* map;
			
		};
	}
}

