#pragma once

#include "..\GinPch.h"

#include "../Graphics/Texture2D.h"
#include "../Graphics/Shader.h"

namespace Gin 
{
	namespace Resources
	{
		class  ResourceLoader
		{
		public:
			// Resource storage
			static std::map<std::string, Graphics::Texture2D> Textures;
			static std::map<std::string, Graphics::Shader> Shaders;

			// Loads (and generates) a texture from file
			static Graphics::Texture2D LoadTexture(const char *file, unsigned char alpha, std::string name);

			// Retrieves a stored texture
			static Graphics::Texture2D GetTexture(std::string name);

			// Loads (and generates) a shader program from file loading vertex, fragment (and geometry) shader's source code. If gShaderFile is not nullptr, it also loads a geometry shader
			static Graphics::Shader LoadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name);
			
			// Retrieves a stored sader
			static Graphics::Shader GetShader(std::string name);

			// Retrieves a stored texture
			static void Clear();

		private:
			// Loads a single texture from file
			static Graphics::Texture2D loadTextureFromFile(const char *file, unsigned char alpha);

			// Loads and generates a shader from file
			static Graphics::Shader loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
		};
	}
}
