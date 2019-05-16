#pragma once

#include "Gin.h"

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

	};

}