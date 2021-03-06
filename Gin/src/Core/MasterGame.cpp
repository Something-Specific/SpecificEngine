
#include "..\GinPch.h"
#include "MasterGame.h"

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <entt/entt.hpp>

namespace Gin
{
	namespace Core
	{

		using namespace Graphics;
		using namespace Inputs;
		using namespace std::chrono;

		MasterGame::MasterGame(float width, float height)
		{
			screen = new Screen(width, height);
			inputProcessor = new Processor(screen->window);

			scene = new Scene(

			);

			//In ticks 1/60 of a seconds.
			TargetTimeStep = UPDATE_TIME_STEP;
			LastUpdateTime = high_resolution_clock::now();
			LastRenderTime = high_resolution_clock::now();
			LastFPSRefresh = high_resolution_clock::now();

			CORE_INFO("Gin initialized.");
		}

		MasterGame::~MasterGame()
		{
			screen->~Screen();
			inputProcessor->~Processor();
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
				if (TargetTimeStep)
				{ //Fixed time step

					//Time since last time in ticks (1 second = 10,000,000 seconds)
					CumulativeDt += dur.count();
					while (CumulativeDt >= TargetTimeStep)
					{
						Update(inputProcessor, static_cast<float>(TargetTimeStep));
						CumulativeDt -= TargetTimeStep;
					}
				}
				else
				{ //Fast as possible
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

		void MasterGame::SetTimeStep(double seconds)
		{
			TargetTimeStep = seconds;
		}

		// Currently lets you add multiple actions with the same name
		void MasterGame::RegisterAction(Action action)
		{
			inputProcessor->RegisteredActions.push_back(action);
		}
	} // namespace Core
} // namespace Gin
