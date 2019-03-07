

#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Texture2D.h"

namespace Core
{
	namespace Graphics
	{
		class Renderer
		{
		public:
			Renderer();
			~Renderer();
			void Start();
			void Stop();
			void Render(Texture2D &texture, glm::vec2 position, glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
		
		private:

			GLuint quadVAO;
			void initRenderData();
		};
	}
}


#endif