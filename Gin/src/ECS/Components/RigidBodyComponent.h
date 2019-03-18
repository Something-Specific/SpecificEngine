#pragma once

#include "..\Contracts\IComponent.h"
#include "..\..\Maths\Vector2.h"

namespace Gin {
	namespace ECS {
		using namespace Maths;

		class RigidbodyComponent : public IComponent {
		public:

			Vector2i *Size;

			RigidbodyComponent() {
				Size = new Vector2i();
			}
			RigidbodyComponent(int x, int y) {
				Size = new Vector2i(x, y);
			}
			RigidbodyComponent(Vector2i *size) {
				Size = size;
			}

			ComponentType GetType() {
				return ComponentType::Rigidbody;
			}

			~RigidbodyComponent() {
			}

		};
	}
}