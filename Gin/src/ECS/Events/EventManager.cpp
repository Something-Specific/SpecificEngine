#include "..\..\GinPch.h"
#include "EventManager.h"


namespace Gin {
	namespace ECS {

		EventManager::EventManager()
		{
			EntityEvents = new vector<function<void(ECS::Entity*)>>();
		}

		EventManager::~EventManager()
		{
			EntityEvents->clear();
			delete EntityEvents;
		}

		void EventManager::RegisterEntityAddedEvent(function<void(ECS::Entity*)> func) {
			EntityEvents->push_back(func);
		}
		void EventManager::InvokeEntityAddedEvent(ECS::Entity* entity) {
			for (auto func = EntityEvents->cbegin(); func < EntityEvents->cend(); ++func) {
				(*func)(entity);
			}
		}
	}
}

