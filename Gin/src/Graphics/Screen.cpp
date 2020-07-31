
#include "Screen.h"

namespace Gin
{
	namespace Graphics
	{

		Screen::Screen(float width, float height)
		{
			this->CreateScreenWindow(width, height);
			this->CreateScreenRenderer(width, height);
		}

		void Screen::CreateScreenWindow(float width, float height)
		{
			if (!glfwInit())
				throw __uncaught_exception;

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

			window = glfwCreateWindow(static_cast<int>(width), static_cast<int>(height), "Something Specific", nullptr, nullptr);
			glfwMakeContextCurrent(window);

			gladLoadGL();
			glGetError();

			glViewport(0, 0, static_cast<int>(width), static_cast<int>(height));
			glEnable(GL_CULL_FACE);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		void Screen::CreateScreenRenderer(float width, float height)
		{
			glm::mat4 projection = glm::ortho(0.0f, width, height, 0.0f, -1.0f, 1.0f);

			Shader shader = Resources::ResourceLoader::LoadShader("rsc/Shaders/sprite.vs", "rsc/Shaders/sprite.frag", nullptr, "sprite");

			shader.Use().SetInteger("image", 0);
			shader.SetMatrix4("projection", projection);

			renderer = new Renderer(shader);
		}

		Screen::~Screen()
		{
			renderer->~Renderer();
		}

		bool Screen::ShouldClose()
		{
			return glfwWindowShouldClose(this->window);
		}

		void Screen::Start()
		{
			glClearColor(0.9f, 0.4f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			//glBegin(GL_2D);
		}

		void Screen::Stop()
		{
			//glEnd();
			glfwSwapBuffers(window);
		}
	} // namespace Graphics
} // namespace Gin
