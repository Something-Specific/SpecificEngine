#pragma once

#include "..\Contracts\INode.h"
#include "..\Components\ComponentType.h"
#include "..\Components\IdentityComponent.h"
#include "..\Components\DisplayComponent.h"
#include "..\Components\PositionComponent.h"
#include "..\Components\RigidbodyComponent.h"
#include "..\Entity.h"


namespace Gin {
	namespace ECS {

		class RenderNode : public INode {
		public:

			IdentityComponent *Identity;
			DisplayComponent *Display;
			PositionComponent *Position;
			RigidbodyComponent *Rigidbody;


			static bool TryCreate(Entity* target, RenderNode *node) {
				RigidbodyComponent *rigidbody = 0;
				PositionComponent *position = 0;
				IdentityComponent *identity = 0;
				DisplayComponent *display = 0;

				if (!target->TryGetComponent(ComponentType::Rigidbody, rigidbody) ||
					!target->TryGetComponent(ComponentType::Display, display) ||
					!target->TryGetComponent(ComponentType::Position, position) ||
					!target->TryGetComponent(ComponentType::Identity, identity)) {
					return false;
				}
				node->Rigidbody = rigidbody;
				node->Display = display;
				node->Position = position;
				node->Identity = identity;
				return true;
			}
			

		};

	}
}
