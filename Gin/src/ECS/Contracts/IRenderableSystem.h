#pragma once

#include "..\..\Graphics\Renderer.h"

namespace Gin {
	namespace ECS {
		class IRenderableSystem
		{
		public:
			virtual void Render(float dt, Graphics::Renderer* renderer) = 0;
		};

	}
}