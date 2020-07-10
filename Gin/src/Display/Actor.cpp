#pragma once

#include "..\GinPch.h"
#include "Actor.h"

namespace Gin {
	namespace Display {
		Actor::Actor() {
			eventDispatcher = new Events::EventDispatcher();
		}

		Actor::~Actor() {

		}

		void Actor::Update(Inputs::Processor* processor, float dt) {

		}

		void Actor::Render(Graphics::Renderer* renderer, float dt) {

		}

		void Actor::AddEventListener(const Events::Event::EventType& eventType, Events::EventDispatcher::EventHandler&& eventHandler) {
			eventDispatcher->addEventListener(eventType, std::move(eventHandler));
		}

		void Actor::DispatchEvent(const Events::Event& event) {

		}
	}
}