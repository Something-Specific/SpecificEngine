
#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Core 
{
	namespace Graphics
	{
		class Shader
		{
		public:
			// State
			unsigned int ID;

			// Constructor
			Shader() { }

			// Sets the current shader as active
			Shader  &Use();

			// Compiles the shader from given source code

			void    Compile(const char *vertexSource, const char *fragmentSource, const char *geometrySource = nullptr); // Note: geometry source code is optional 
			// Utility functions
			void    SetFloat(const char *name, float value, unsigned char useShader = false);
			void    SetInteger(const char *name, int value, unsigned char useShader = false);
			void    SetVector2f(const char *name, float x, float y, unsigned char useShader = false);
			void    SetVector2f(const char *name, const glm::vec2 &value, unsigned char useShader = false);
			void    SetVector3f(const char *name, float x, float y, float z, unsigned char useShader = false);
			void    SetVector3f(const char *name, const glm::vec3 &value, unsigned char useShader = false);
			void    SetVector4f(const char *name, float x, float y, float z, float w, unsigned char useShader = false);
			void    SetVector4f(const char *name, const glm::vec4 &value, unsigned char useShader = false);
			void    SetMatrix4(const char *name, const glm::mat4 &matrix, unsigned char useShader = false);

		private:
			// Checks if compilation or linking failed and if so, print the error logs
			void    checkCompileErrors(unsigned int object, std::string type);
		};
	}
}

#endif