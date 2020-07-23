#pragma once

#include "Gin.h"
#include <glm/glm.hpp>

namespace Demo
{
	using namespace Gin;

	class Game : public Core::MasterGame
	{
	public:
		void Update(Inputs::Processor *processor, float dt);
		void Render(Graphics::Renderer *renderer, float dt);

	private:
		void Init();
		Graphics::Texture2D Texture;
		glm::vec2 Position;
		glm::vec2 Size;
	};

} // namespace Demo