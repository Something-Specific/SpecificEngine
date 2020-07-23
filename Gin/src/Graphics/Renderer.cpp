
#include "..\GinPch.h"
#include "Renderer.h"

namespace Gin::Graphics
{
	Renderer::Renderer(Shader &shader)
	{
		DefaultShader = shader;
		CreateRenderData();
	}

	Renderer::~Renderer()
	{
		glDeleteVertexArrays(1, &quadVAO);
	}

	void Renderer::CreateRenderData()
	{
		// Configure VAO/VBO
		unsigned int VBO;

		float vertices[] = {
			// Pos      // Tex
			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,

			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f};

		glGenVertexArrays(1, &quadVAO);
		glGenBuffers(1, &VBO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glBindVertexArray(quadVAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void Renderer::Render(Texture2D &texture, glm::vec2 position, float rotate, glm::vec3 color)
	{
		Render(texture, position, glm::vec2(static_cast<float>(texture.Width), static_cast<float>(texture.Height)), rotate, color);
	}

	void Renderer::Render(Texture2D &texture, glm::vec2 position, glm::vec2 size, float rotate, glm::vec3 color)
	{
		// Prepare transformations
		DefaultShader.Use();
		glm::mat4 model = glm::mat4(1.0f);
		// First translate (transformations are: scale happens first, then rotation and then finall translation happens; reversed order)
		model = glm::translate(model, glm::vec3(position, 0.0f));
		// Move origin of rotation to center of quad
		model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
		// Then rotate
		model = glm::rotate(model, rotate, glm::vec3(0.0f, 0.0f, 1.0f));
		// Move origin back
		model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
		// Last scale
		model = glm::scale(model, glm::vec3(size, 1.0f));

		DefaultShader.SetMatrix4("model", model);

		// Render textured quad
		DefaultShader.SetVector3f("spriteColor", color);

		glActiveTexture(GL_TEXTURE0);
		texture.Bind();

		glBindVertexArray(quadVAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
	}
} // namespace Gin::Graphics
