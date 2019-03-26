#pragma once

#include "Gin.h"

namespace Demo
{
	using namespace Gin;

	class Game : public Gin::Core::MasterGame
	{
	public:
		void Update(Gin::Inputs::Processor *processor, float dt);
		void Render(Gin::Graphics::Renderer *renderer, float dt);

	private:
		void Init();

		ECS::Engine* CoreEngine;
	};

}