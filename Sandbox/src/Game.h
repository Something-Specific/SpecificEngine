#pragma once

#include "Gin.h"

namespace Demo
{
	using namespace Gin;

	class Game : public Gin::Core::MasterGame
	{
	public:
		void Update(float dt);
		void Render(Gin::Graphics::Renderer *renderer);

	private:
		void Init();

		ECS::Engine* CoreEngine;
	};

}