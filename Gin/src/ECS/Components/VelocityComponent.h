#pragma once

#include "..\Components\ComponentType.h"
#include "..\Contracts\IComponent.h"
#include "..\..\Maths\Vector2.h"

namespace Gin {
	namespace ECS {

		using namespace Maths;

		class VelocityComponent : public IComponent {
		public:

			Vector2f *Position;

			VelocityComponent() {
				Position = new Vector2f();
			}
			VelocityComponent(float x, float y) {
				Position = new Vector2f(x, y);
			}
			VelocityComponent(Vector2f *pos) {
				Position = pos;
			}

			ComponentType GetType() {
				return ComponentType::Velocity;
			}

			~VelocityComponent() {
				delete Position;
			}

		};
	}
}