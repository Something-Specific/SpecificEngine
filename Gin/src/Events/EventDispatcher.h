#pragma once
#include "..\GinPch.h"
#include "Event.h"

namespace Gin {
	namespace Events {
		class EventDispatcher
		{
		public:
			using EventHandler = std::function< void(const Event&) >;

			void addEventListener(const Event::EventType& descriptor, EventHandler&& handler);

			void dispatch(const Event& event) const;

		private:

			std::map<Event::EventType, std::vector<EventHandler>> eventHandlers;
		};
	}
}