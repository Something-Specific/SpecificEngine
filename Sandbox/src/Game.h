#pragma once

#include "Gin.h"

namespace Demo
{

	class Game : public Gin::Core::MasterGame
	{
	public:
		void Update(Gin::Inputs::Processor *processor, float dt) override;
		void Render(Gin::Graphics::Renderer *renderer, float dt) override;

	private:
		void Init();
	};

} // namespace Demo