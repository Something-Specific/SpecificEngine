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


			static bool TryCreate(Entity* target, RenderNode* node) {
				RigidbodyComponent** rigidbody = nullptr;
				PositionComponent** position = nullptr;
				IdentityComponent** identity = nullptr;
				DisplayComponent** display = nullptr;

				if (!target->TryGetComponent(ComponentType::Rigidbody, (IComponent**) &rigidbody) ||
					!target->TryGetComponent(ComponentType::Display, (IComponent**) &display) ||
					!target->TryGetComponent(ComponentType::Position, (IComponent**) &position) ||
					!target->TryGetComponent(ComponentType::Identity, (IComponent**) &identity)) {
					return false;
				}
				node->Rigidbody = *rigidbody;
				node->Display = *display;
				node->Position = *position;
				node->Identity = *identity;
				return true;
			}
			

		};

	}
}
