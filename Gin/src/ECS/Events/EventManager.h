#pragma once

#include <functional>
#include <stdio.h>
#include "..\Entity.h"

namespace Gin {
	namespace ECS {

		using namespace std;
		using namespace placeholders;

		class EventManager
		{
		public:
			EventManager();
			~EventManager();

			void RegisterEntityAddedEvent(function<void(ECS::Entity*)> func);
			void InvokeEntityAddedEvent(ECS::Entity*);

		private:
			vector<function<void(ECS::Entity*)>> *EntityEvents;

		};
	}
}

