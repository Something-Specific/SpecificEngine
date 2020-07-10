#pragma once

#include "..\GinPch.h"
#include "Sprite.h"

namespace Gin {
	namespace Display {

		Sprite::Sprite(Graphics::Texture2D* texture) {
			this->texture = texture;
		}

		Sprite::~Sprite() {

		}

		void Sprite::Update(Inputs::Processor* processor, float dt) {
			this->Actor::Update(processor, dt);
		}

		void Sprite::Render(Graphics::Renderer* renderer, float dt) {
			this->Actor::Render(renderer, dt);
			renderer->Render(*texture, position, scale, rotation);
		}
	}
}