#pragma once

#include "..\..\Graphics\Texture2D.h"
#include "..\Contracts\IComponent.h"

namespace Gin {
	namespace ECS {
		class DisplayComponent : public IComponent {
		public:
			
			Graphics::Texture2D *Sprite;

			DisplayComponent(Graphics::Texture2D *sprite) {
				Sprite = sprite;
			}

			ComponentType GetType() {
				return ComponentType::Display;
			}

			~DisplayComponent() {
				delete Sprite;
			}
		};

	}
}