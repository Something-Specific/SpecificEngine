#pragma once

#include "..\Contracts\IComponent.h"
#include "..\..\Maths\Vector2.h"

namespace Gin {
	namespace ECS {

		using namespace Maths;

		class PositionComponent : public IComponent {
		public:

			Vector2f *Position;

			PositionComponent() {
				Position = new Vector2f();
			}
			PositionComponent(float x, float y) {
				Position = new Vector2f(x, y);
			}
			PositionComponent(Vector2f *pos) {
				Position = pos;
			}

			ComponentType GetType() {
				return ComponentType::Position;
			}

			~PositionComponent() {
				delete Position;
			}

		};
	}
}