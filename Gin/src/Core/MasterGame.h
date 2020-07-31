#pragma once

#include "..\GinPch.h"

#include "Scene.h"
#include "..\Graphics\Screen.h"
#include "..\Graphics\Renderer.h"
#include "..\Inputs\Processor.h"

constexpr auto FPS_REFRESH_RATE = 0.25;
// constexpr auto UPDATE_TIME_STEP = 0.016666666666666666; // 60hz
constexpr auto UPDATE_TIME_STEP = 0.008333333333333333; // 120hz
// constexpr auto UPDATE_TIME_STEP = 0.004166666666666666; // 240hz

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
			double CumulativeDt; //In ticks
			double TargetTimeStep;
			double FramesElapsed;
		};
	} // namespace Core
} // namespace Gin