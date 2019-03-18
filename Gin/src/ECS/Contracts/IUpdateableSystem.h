#pragma once

#include "..\..\Inputs\Processor.h"

namespace Gin {
	namespace ECS {
		class IUpdateableSystem
		{
		public:
			virtual void Update(float dt, Inputs::Processor* processor) = 0;
		};

	}
}