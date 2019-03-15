
#include "..\GinPch.h"
#include "MasterGame.h"

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


namespace Gin
{
	namespace Core
	{

		MasterGame::MasterGame(float width, float height)
		{
			screen = new Screen(width, height);
			processor = new Processor(screen->window);

			//In ticks 1/60 of a second.s
			TargetTimeStep = UPDATE_TIME_STEP;
			LastUpdateTime = high_resolution_clock::now();
			LastFPSRefresh = high_resolution_clock::now();

			CORE_INFO("Gin initialized.");
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

				//Update Loop
				auto time = high_resolution_clock::now();
				auto dur = duration_cast<duration<double>>(time - LastUpdateTime);
				if (TargetTimeStep) { //Fixed time step

					//Time since last time in ticks (1 second = 10,000,000 seconds)
					CumulativeDt += static_cast<uint64_t>(dur.count() * TICKS_IN_SECOND);
					while (CumulativeDt >= TargetTimeStep)
					{
						auto dt = static_cast<float>(TargetTimeStep / (TICKS_IN_SECOND * 1.0));
						Update(dt);
						CumulativeDt -= TargetTimeStep;
					}
				}
				else { //Fast as possible
					Update(static_cast<float>(dur.count()));
				}
				LastUpdateTime = high_resolution_clock::now();

				//FPS Counter
				FramesElapsed++;
				dur = duration_cast<duration<double>>(LastUpdateTime - LastFPSRefresh);
				if (dur.count() > FPS_REFRESH_RATE)
				{
					double fps = FramesElapsed / dur.count();
					//char fpsStr[20];
					//std::sprintf(fpsStr, "Gin\tFPS%g", fps);

					std::stringstream title;
					title << "Gin - FPS: " << fps;


					glfwSetWindowTitle(screen->window, title.str().c_str());
					FramesElapsed = 0;
					LastFPSRefresh = high_resolution_clock::now();
				}


				//Render Loop
				screen->Start();
				Render(screen->renderer);
				//renderer->Render(tex, glm::vec2(64, 64), glm::vec2(128, 128));
				screen->Stop();
			}

			glfwTerminate();
		}


		void MasterGame::SetTimeStep(int ticks)
		{

		}
		
		void MasterGame::SetTimeStep(double seconds)
		{

		}
	}
}
