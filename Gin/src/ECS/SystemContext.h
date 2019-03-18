#pragma once

#include "Contracts/IEventManager.h"
#include "Contracts/ISystemContext.h"

namespace Gin {
	namespace ECS {
		class SystemContext : public ISystemContext
		{
		public:
			float ViewportWidth;
			float ViewportHeight;
			IEventManager *Events;

			SystemContext(IEventManager *events, float viewportWidth = 640, float viewportHeight = 480) {
				Events = events;
				ViewportWidth = viewportWidth;
				ViewportHeight = viewportHeight;
			}
			~SystemContext() {
				delete Events;
			}
		};
	}
}