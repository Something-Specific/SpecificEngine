#pragma once

#include "..\GinPch.h"
#include "..\Graphics\Renderer.h"
#include "..\Inputs\Processor.h"
#include "Actor.h"

#include <list>

namespace Gin {
	namespace Display {
		class Stage
		{
		public:
			Stage();
			~Stage();

			void AddChild(Actor* actor);
			void RemoveChild(Actor* actor);
			void Update(Inputs::Processor* processor, float dt);
			void Render(Graphics::Renderer* renderer, float dt);

		private:
			std::list<Actor*>* Actors;
		};
	}
}

