#pragma once

#include "IEventManager.h"

namespace Gin {
	namespace ECS {
		class ISystemContext
		{
		public:
			IEventManager Events;
			float ViewportHeight;
			float ViewportWidth;
		};
	}
}

