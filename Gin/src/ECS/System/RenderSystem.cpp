
#include "..\..\GinPch.h"

#include "RenderSystem.h"

namespace Gin {
	namespace ECS {

		RenderSystem::RenderSystem(ISystemContext *context)
		{
			Context = context;
		}

		void RenderSystem::Render(float dt, Graphics::Renderer* renderer) {
			for (auto target = Targets->begin(); target != Targets->end(); target++) {
				renderer->Render(
					*((*target)->Display->Sprite), 
					*((*target)->Position->Position),
					*((*target)->Rigidbody->Size));
			}
		}

		//TODO: until events are figured out this just takes an entity
		void RenderSystem::OnEntityAddedEvent(Entity *e) {
			RenderNode *node = new RenderNode();
			if (RenderNode::TryCreate(e, node)) {
				Targets->push_front(node);
			}
		}

		RenderSystem::~RenderSystem()
		{
			Targets->clear();
			delete Targets;
		}
	}
}

