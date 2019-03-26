
#include "..\GinPch.h"

#include "Summoner.h"


//TODO: should be moved to project settings or macro file.
#define GAINPUT_PLATFORM_WIN

namespace Gin
{
	namespace Inputs
	{

		Summoner::Summoner(float width, float height)
		{
			processor = new Processor();
			//manager = new gainput::InputManager();
			manager->SetDisplaySize(static_cast<int>(width), static_cast<int>(height));
		}

		void Summoner::Update()
		{
			manager->Update();
		}

		Summoner::~Summoner()
		{
			manager->end();
			//delete manager;
		}


	}
}
