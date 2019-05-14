#pragma once

#include "..\Contracts\IRenderableSystem.h"
#include "..\Nodes\Rendernode.h"
#include "..\Entity.h"
#include <list>

namespace Gin {
	namespace ECS {
		class RenderSystem : public IRenderableSystem
		{
		public:
			RenderSystem(SystemContext *context);
			~RenderSystem();

			void OnEntityAddedEvent(Entity *e);
			void Render(float dt, Graphics::Renderer* renderer);

		private:
			std::list<RenderNode*> *Targets;
			SystemContext *Context;
		};
	}
}


