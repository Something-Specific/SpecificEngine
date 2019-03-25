#pragma once

#include <functional>
#include <stdio.h>
#include "EventTypes.h"

namespace Gin {
	namespace Events {

		using namespace std;
		using namespace placeholders;

		class EventManager
		{
		public:
			EventManager();
			~EventManager();

			void RegisterKeyboardEvent(function<void(int, int)> func);
			void InvokeKeyboardEvent(int key, int action);

		private:
			vector<function<void(int, int)>> *KeyboardEvents;

		};
	}
}

