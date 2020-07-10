#pragma once

#include "..\GinPch.h"
#include "..\Events\EventDispatcher.h"

namespace Gin {
	namespace Display {
		class  Actor {
		public:
			Actor();
			~Actor();
			void Update(Inputs::Processor* processor, float dt);
			void Render(Graphics::Renderer* renderer, float dt);
			Events::EventDispatcher eventDispatcher;
		private:
			Maths::Vector2f position;
			Maths::Vector2f scale;
			float rotation;
		};
	}
}