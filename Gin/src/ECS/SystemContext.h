#pragma once

#include "Events/EventManager.h"

namespace Gin {
	namespace ECS {
		class SystemContext
		{
		public:

			SystemContext(float viewportWidth = 640, float viewportHeight = 480) {
				Events = new EventManager();
				ViewportWidth = viewportWidth;
				ViewportHeight = viewportHeight;
			}
			~SystemContext() {
				delete Events;
			}

			EventManager* Events;
			float ViewportWidth;
			float ViewportHeight;

		};
	}
}