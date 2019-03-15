
#include "..\GinPch.h"
#include "MasterGame.h"

namespace Gin
{
	namespace Core
	{
		MasterGame::MasterGame(float width, float height)
		{
			screen = new Graphics::Screen(width, height);
			processor = new Inputs::Processor(screen->window);
		}

		MasterGame::~MasterGame()
		{
			screen->~Screen();
		}

		void MasterGame::Run()
		{
			Init();
			while (!screen->ShouldClose())
			{
				//Ready all events
				glfwPollEvents();

				//Process input


				//Update
				Update(0);


				//Render
				screen->Start();
				Render(screen->renderer);
				//renderer->Render(tex, glm::vec2(64, 64), glm::vec2(128, 128));
				screen->Stop();
			}

			glfwTerminate();
		}
	}
}
