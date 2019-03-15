#pragma once

#include "Gin.h"

namespace Demo
{

	class Game : public Gin::Core::MasterGame
	{
	public:
		void Update(float dt);
		void Render(Gin::Graphics::Renderer *renderer);

	private:
		void Init();
	};

}