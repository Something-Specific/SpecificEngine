#pragma once

#include "..\GinPch.h"

#include "Scene.h"
#include "..\Graphics\Screen.h"
#include "..\Graphics\Renderer.h"
#include "..\Inputs\Processor.h"

constexpr auto FPS_REFRESH_RATE = 0.25;
constexpr auto UPDATE_TIME_STEP = 1666667;
constexpr auto TICKS_IN_SECOND = 10000000;

namespace Gin
{
	namespace Core
	{

		class MasterGame
		{
		public:
			MasterGame(float width = 640, float height = 480);
			~MasterGame();

			void Run();
			void SetTimeStep(int ticks);
			void SetTimeStep(double seconds);

			virtual void Update(Inputs::Processor *processor, float dt) {}
			virtual void Render(Graphics::Renderer *renderer, float dt) {}

		protected:
			Scene *scene;

			virtual void Init() {}

		private:
			Graphics::Screen *screen;
			Inputs::Processor *inputProcessor;

			std::chrono::time_point<std::chrono::steady_clock> LastUpdateTime;
			std::chrono::time_point<std::chrono::steady_clock> LastRenderTime;
			std::chrono::time_point<std::chrono::steady_clock> LastFPSRefresh;
			uint64_t CumulativeDt; //In ticks
			uint64_t TargetTimeStep;
			uint64_t FramesElapsed;
		};
	} // namespace Core
} // namespace Gin