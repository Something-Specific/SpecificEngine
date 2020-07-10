#pragma once

#include "..\GinPch.h"

namespace Gin
{
	namespace Events {
		class Event {
		public:
			virtual ~Event();

			using EventType = const char*;
			virtual EventType type() const = 0;
		};
	}
}

/* Sample implementation
class DemoEvent : public Event
{
public:
	DemoEvent();
	virtual ~DemoEvent();

	static constexpr EventType eventType = "DemoEvent";

	virtual EventType type() const
	{
		return eventType;
	}
};
*/