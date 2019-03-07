
#include <GL\glew.h>
#include <GLFW\glfw3.h>
//#include <glm\glm.hpp>

#include <iostream>

#include "Core\Resources\ResourceLoader.h"
#include "Core\Graphics\Texture2D.h"
#include "Core\Graphics\Renderer.h"

int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Something Specific", NULL, NULL);

	//Core::Graphics::Texture2D tex = Core::Resources::ResourceLoader::LoadTexture("../rsc/card_back.pn", GL_TRUE, "CardBack");
	//Core::Graphics::Renderer renderer = Core::Graphics::Renderer();
	//glm::vec2 pos = glm::vec2(0,0);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);


		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f( 0.5f, -0.5f);

		//renderer.Render(tex, pos);

		glEnd();


		glfwSwapBuffers(window);

		glfwPollEvents();

	}

	glfwTerminate();
	return 0;
}