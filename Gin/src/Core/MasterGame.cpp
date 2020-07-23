
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
			inputProcessor = new Processor();

			//In ticks 1/60 of a seconds.
			TargetTimeStep = UPDATE_TIME_STEP;
			LastUpdateTime = high_resolution_clock::now();
			LastRenderTime = high_resolution_clock::now();
			LastFPSRefresh = high_resolution_clock::now();

			CORE_INFO("Gin initialized.");

			stage = new Stage();
		}

		MasterGame::~MasterGame()
		{
			screen->~Screen();
			inputProcessor->~Processor();
			stage->~Stage();
		}

		void MasterGame::Run()
		{
			Init();
			while (!screen->ShouldClose())
			{
				//TODO: Not sure where this should be probably should be in some window abstraction
				//Ready all events
				glfwPollEvents();

				//Process input
				// TODO

				//Update Loop
				auto time = high_resolution_clock::now();
				auto dur = duration_cast<duration<double>>(time - LastUpdateTime);
				if (TargetTimeStep) { //Fixed time step

					//Time since last time in ticks (1 second = 10,000,000 seconds)
					CumulativeDt += static_cast<uint64_t>(dur.count() * TICKS_IN_SECOND);
					while (CumulativeDt >= TargetTimeStep)
					{
						auto dt = static_cast<float>(TargetTimeStep / (TICKS_IN_SECOND * 1.0));
						Update(inputProcessor, dt);
						CumulativeDt -= TargetTimeStep;
					}
				}
				else { //Fast as possible
					Update(inputProcessor, static_cast<float>(dur.count()));
				}
				LastUpdateTime = high_resolution_clock::now();

				//FPS Counter
				FramesElapsed++;
				dur = duration_cast<duration<double>>(high_resolution_clock::now() - LastFPSRefresh);
				if (dur.count() > FPS_REFRESH_RATE)
				{
					double fps = FramesElapsed / dur.count();
					std::stringstream title;
					title << "Gin - FPS: " << fps;
					glfwSetWindowTitle(screen->window, title.str().c_str());
					FramesElapsed = 0;
					LastFPSRefresh = high_resolution_clock::now();
				}


				//Render Loop
				screen->Start();
				dur = duration_cast<duration<double>>(high_resolution_clock::now() - LastRenderTime);
				Render(screen->renderer, static_cast<float>(dur.count()));
				LastRenderTime = high_resolution_clock::now();
				screen->Stop();
			}

			glfwTerminate();
		}


		void MasterGame::SetTimeStep(int ticks)
		{
			TargetTimeStep = ticks;
		}
		
		void MasterGame::SetTimeStep(double seconds)
		{
			TargetTimeStep = TICKS_IN_SECOND * seconds;
		}
	}
}
