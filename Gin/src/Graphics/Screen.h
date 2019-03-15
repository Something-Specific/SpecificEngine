#pragma once

#include "..\GinPch.h"

#include "..\Resources\ResourceLoader.h"
#include "Texture2D.h"
#include "Renderer.h"

namespace Gin
{
	namespace Graphics
	{
		class  Screen 
		{

		public:
			GLFWwindow *window;
			Renderer *renderer;

			Screen(float width, float height);
			~Screen();

			void Start();
			void Stop();

			bool ShouldClose();

		private:
			void CreateScreenWindow(float width, float height);
			void CreateScreenRenderer(float width, float height);

		};
	}
}