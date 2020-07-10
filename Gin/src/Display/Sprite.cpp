#pragma once

#include "..\GinPch.h"
#include "Sprite.h"

namespace Gin {
	namespace Display {

		Sprite::Sprite(Graphics::Texture2D* texture, float x, float y, float w, float h) {
			this->texture = texture;
			this->position = Gin::Maths::Vector2f(x, y);
			this->scale = Gin::Maths::Vector2f(w, h);
			this->rotation = 0;
		}

		Sprite::~Sprite() {
		}

		void Sprite::Update(Inputs::Processor* processor, float dt) {
			this->Actor::Update(processor, dt);
		}

		void Sprite::Render(Graphics::Renderer* renderer, float dt) {
			this->Actor::Render(renderer, dt);
			renderer->Render(*texture, position, scale, rotation);
			GAME_INFO("Sprite is rendering");
		}
	}
}