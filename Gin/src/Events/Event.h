#pragma once

#include "..\GinPch.h"

namespace Gin {
	namespace Events {


		enum class EventType {
			None = 0,
			WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
			AppTick, AppUpdate, AppRender,
			KeyPressed, KeyReleased,
			MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
		};

		enum EventCategory {
			None						= 0,
			EventCategoryApplication	= BIT(0),
			EventCategoryInput			= BIT(1),
			EventCategoryKeyboard		= BIT(2),
			EventCategoryMouse			= BIT(3),
			EventCategoryMouseButton	= BIT(4)
		};
	}
}