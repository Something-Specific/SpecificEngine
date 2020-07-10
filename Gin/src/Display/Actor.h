#pragma once

#include "..\GinPch.h"
#include "..\Events\Event.h"
#include "..\Events\EventDispatcher.h"
#include "..\Inputs\Processor.h"
#include "..\Graphics\Renderer.h"

namespace Gin {
	namespace Display {
		class  Actor {
		public:
			Actor();
			~Actor();
			void Update(Inputs::Processor* processor, float dt);
			void Render(Graphics::Renderer* renderer, float dt);
			void AddEventListener(const Events::Event::EventType& eventType, Events::EventDispatcher::EventHandler&& eventHandler);
			void DispatchEvent(const Events::Event& event);
		protected:
			Maths::Vector2f position;
			Maths::Vector2f scale;
			float rotation;

			Events::EventDispatcher* eventDispatcher;
		};
	}
}