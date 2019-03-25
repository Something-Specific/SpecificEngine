#include "..\GinPch.h"
#include "EventManager.h"


namespace Gin {
	namespace Events {

		EventManager::EventManager()
		{
			KeyboardEvents = new vector<function<void(int, int)>>();
		}


		EventManager::~EventManager()
		{
			KeyboardEvents->clear();
			delete KeyboardEvents;
		}

		void EventManager::RegisterKeyboardEvent(function<void(int, int)> func) {
			KeyboardEvents->push_back(func);
		}
		void EventManager::InvokeKeyboardEvent(int key, int action) {
			for (auto func = KeyboardEvents->cbegin(); func < KeyboardEvents->cend(); ++func) {
				(*func)(key, action);
			}
		}
	}
}

