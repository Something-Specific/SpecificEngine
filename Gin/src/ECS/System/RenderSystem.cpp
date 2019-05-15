
#include "..\..\GinPch.h"

#include "..\SystemContext.h"
#include "RenderSystem.h"

namespace Gin {
	namespace ECS {

		RenderSystem::RenderSystem(SystemContext *context)
		{
			Context = context;
			Targets = new std::list<RenderNode*>();	
			
			auto func = std::bind(&RenderSystem::OnEntityAddedEvent, this, _1);
			Context->Events->RegisterEntityAddedEvent(func);
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
			RenderNode *node = (RenderNode*)malloc(sizeof(RenderNode));
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

