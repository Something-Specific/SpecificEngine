#pragma once

#include "..\GinPch.h"

#include "..\Graphics\Screen.h"
#include "..\Inputs\Processor.h"


namespace Gin
{
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

			virtual void Update(float dt) {}
			virtual void Render(Graphics::Renderer *renderer) {}

		protected:
			virtual void Init() {}
		};
	}
}