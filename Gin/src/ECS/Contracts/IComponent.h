#pragma once

#include "..\Components\ComponentType.h"

namespace Gin {
	namespace ECS {
		class IComponent
		{
		public:
			virtual ComponentType GetType() = 0;
		};
	}
}


