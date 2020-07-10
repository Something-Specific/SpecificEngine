#pragma once

#include "Gin.h"

namespace DemoEvent {

	class DemoEvent : public Gin::Events::Event {

	public:
		static constexpr EventType eventType = "DemoEvent";

		~DemoEvent()
		{
		}

		EventType type() const {
			return eventType;
		}
	};
};