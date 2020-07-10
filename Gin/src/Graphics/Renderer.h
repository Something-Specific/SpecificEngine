#pragma once

#include "..\GinPch.h"

#include "..\Maths\Vector2.h"
#include "Texture2D.h"
#include "Shader.h"

namespace Gin
{
	namespace Graphics
	{
		class  Renderer
		{

		public:
			Renderer(Shader &shader);
			~Renderer();

			void Render(Texture2D &texture, Maths::Vector2f position);
			void Render(Texture2D &texture, Maths::Vector2f position, Maths::Vector2f size);
			void Render(Texture2D& texture, Maths::Vector2f position, Maths::Vector2f size, float rotate);

			void Render(Texture2D &texture, glm::vec2 position, float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
			void Render(Texture2D &texture, glm::vec2 position, glm::vec2 size, float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
		
		private:
			Shader DefaultShader;
			GLuint quadVAO;
			void CreateRenderData();

		};
	}
}
