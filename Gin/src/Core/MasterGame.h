#pragma once

#include "..\GinPch.h"

#include "..\Graphics\Screen.h"
#include "..\Inputs\Processor.h"
#include "..\ECS\Engine.h"

#define FPS_REFRESH_RATE 0.25
#define UPDATE_TIME_STEP 1666667
#define TICKS_IN_SECOND 10000000

namespace Gin
{
	namespace Core
	{
		using namespace Graphics;
		using namespace Inputs; 
		using namespace std::chrono;

		class MasterGame
		{
		public:
			Graphics::Screen *screen;
			Inputs::Processor *processor;

			MasterGame(float width = 640, float height = 480);
			~MasterGame();

			void Run();
			void SetTimeStep(int ticks);
			void SetTimeStep(double seconds);

			virtual void Update(float dt) {}
			virtual void Render(Graphics::Renderer *renderer) {}

		protected:
			ECS::Engine* CoreEngine;

			virtual void Init() {}

		private:
			time_point<steady_clock> LastUpdateTime;
			time_point<steady_clock> LastFPSRefresh;
			uint64_t CumulativeDt; //In ticks
			uint64_t TargetTimeStep;
			uint64_t FramesElapsed;
		};
	}
}