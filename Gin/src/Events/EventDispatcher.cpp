#pragma once
#include "..\GinPch.h"
#include "Event.h"
#include "EventDispatcher.h"

namespace Gin
{
	namespace Events {
		void EventDispatcher::addEventListener(const Event::EventType& eventType, EventHandler&& eventHandler) {
			eventHandlers[eventType].push_back(eventHandler);
		}

		void EventDispatcher::dispatch(const Event& event) const {
			auto type = event.type();

			// Ignore events for which we do not have an observer (yet).
			if (eventHandlers.find(type) == eventHandlers.end())
				return;

			auto&& handlers = eventHandlers.at(type);

			for (auto&& handler : handlers)
				handler(event);
		}
	}
}