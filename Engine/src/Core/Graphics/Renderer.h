

#ifndef RENDERER_H
#define RENDERER_H

#include <gl/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Texture2D.h"
#include "Shader.h"

namespace Core
{
	namespace Graphics
	{
		class Renderer
		{

		public:
			Renderer(Shader &shader);
			~Renderer();
			void Render(Texture2D &texture, glm::vec2 position, float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
			void Render(Texture2D &texture, glm::vec2 position, glm::vec2 size, float rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
		
		private:
			Shader DefaultShader;
			GLuint quadVAO;
			void CreateRenderData();

		};
	}
}

#endif