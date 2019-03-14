

#ifndef MASTER_GAME_H
#define MASTER_GAME_H

#include "Graphics\Screen.h"
#include "Graphics\Renderer.h"
#include "Inputs\Processor.h"

namespace Core
{
	class MasterGame
	{
	public:
		Graphics::Screen *screen;
		Inputs::Processor *processor;

		MasterGame(float width = 640, float height = 480);
		~MasterGame();
		
		void Run();
		virtual void Init() {}

		virtual void Update(float dt) {}
		virtual void Render(Graphics::Renderer *renderer) {}

	};
}

#endif