
#include "..\GinPch.h"

#include "Summoner.h"

namespace Gin
{
	namespace Inputs
	{

		Summoner::Summoner(float width, float height)
		{
			processor = new Processor();
			manager = new gainput::InputManager();

			const auto padId = manager->CreateDevice<gainput::InputDevicePad>();
			manager->SetDisplaySize(static_cast<int>(width), static_cast<int>(height));

			map = new gainput::InputMap(*manager);
			map->MapBool(Primary, padId, gainput::PadButtonA);
			map->MapBool(Secondary, padId, gainput::PadButtonX);
		}

		void Summoner::Update()
		{
			manager->Update();
			if (map->GetBoolWasDown(Primary)) {
				CORE_INFO("Primary button down.");
			}
		}

		Summoner::~Summoner()
		{
			manager->end();
			delete manager;
		}


	}
}
