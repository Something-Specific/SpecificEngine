#pragma once

#include "..\GinPch.h"
#include "..\Events\Event.h"
#include "..\Events\EventDispatcher.h"
#include "..\Inputs\Processor.h"
#include "..\Graphics\Renderer.h"
#include "Actor.h"

namespace Gin {
	namespace Display {
		class  Sprite : public Actor {
		public:
			Sprite(Graphics::Texture2D* texture, float x, float y, float w, float h);
			~Sprite();
			virtual void Update(Inputs::Processor* processor, float dt);
			virtual void Render(Graphics::Renderer* renderer, float dt);
		private:
			Graphics::Texture2D* texture;
		};
	}
}
