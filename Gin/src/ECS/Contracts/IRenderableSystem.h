#pragma once

#include "..\..\Graphics\Renderer.h"
#include "..\Entity.h"

namespace Gin {
	namespace ECS {
		class IRenderableSystem
		{
		public:
			virtual void Render(float dt, Graphics::Renderer* renderer) = 0;
			virtual void OnEntityAddedEvent(Entity* e) = 0;
		};

	}
}