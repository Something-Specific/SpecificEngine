

#ifndef SCREEN_H
#define SCREEN_H

#define GLEW_STATIC

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>

#include <iostream>

#include "..\Resources\ResourceLoader.h"
#include "Texture2D.h"
#include "Renderer.h"

namespace Core
{
	namespace Graphics
	{
		class Screen 
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
			void CreateWindow(float width, float height);
			void CreateRenderer(float width, float height);

		};
	}
}

#endif