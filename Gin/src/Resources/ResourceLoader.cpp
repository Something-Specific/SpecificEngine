
#include "..\GinPch.h"
#include "ResourceLoader.h"

namespace Gin 
{
	namespace Resources 
	{

		std::map<std::string, Graphics::Texture2D> ResourceLoader::Textures;
		std::map<std::string, Graphics::Shader> ResourceLoader::Shaders;

		Graphics::Texture2D ResourceLoader::LoadTexture(const char *file, unsigned char alpha, std::string name)
		{
			Textures[name] = loadTextureFromFile(file, alpha);
			return Textures[name];
		}

		Graphics::Texture2D ResourceLoader::GetTexture(std::string name)
		{
			return Textures[name];
		}

		Graphics::Shader ResourceLoader::LoadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name)
		{
			Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
			return Shaders[name];
		}

		Graphics::Shader ResourceLoader::GetShader(std::string name)
		{
			return Shaders[name];
		}

		Graphics::Texture2D ResourceLoader::loadTextureFromFile(const char *file, unsigned char alpha)
		{
			// Create Texture object
			Graphics::Texture2D texture;
			if (alpha)
			{
				texture.Internal_Format = GL_RGBA;
				texture.Image_Format = GL_RGBA;
			}
			// Load image
			int width, height;
			unsigned char* image = &alpha; // SOIL_load_image(file, &width, &height, 0, texture.Image_Format == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
			// Now generate texture
			texture.Generate(width, height, image);
			// And finally free image data
			//SOIL_free_image_data(image);
			return texture;
		}

		Graphics::Shader ResourceLoader::loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile)
		{
			// 1. Retrieve the vertex/fragment source code from filePath
			std::string vertexCode;
			std::string fragmentCode;
			std::string geometryCode;
			try
			{
				// Open files
				std::ifstream vertexShaderFile(vShaderFile);
				std::ifstream fragmentShaderFile(fShaderFile);
				std::stringstream vShaderStream, fShaderStream;
				// Read file's buffer contents into streams
				vShaderStream << vertexShaderFile.rdbuf();
				fShaderStream << fragmentShaderFile.rdbuf();
				// close file handlers
				vertexShaderFile.close();
				fragmentShaderFile.close();
				// Convert stream into string
				vertexCode = vShaderStream.str();
				fragmentCode = fShaderStream.str();
				// If geometry shader path is present, also load a geometry shader
				if (gShaderFile != nullptr)
				{
					std::ifstream geometryShaderFile(gShaderFile);
					std::stringstream gShaderStream;
					gShaderStream << geometryShaderFile.rdbuf();
					geometryShaderFile.close();
					geometryCode = gShaderStream.str();
				}
			}
			catch (std::exception e)
			{
				std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
			}
			const GLchar *vShaderCode = vertexCode.c_str();
			const GLchar *fShaderCode = fragmentCode.c_str();
			const GLchar *gShaderCode = geometryCode.c_str();
			// 2. Now create shader object from source code
			Graphics::Shader shader;
			shader.Compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
			return shader;
		}

		void ResourceLoader::Clear()
		{
			for (auto iter : Textures)
				glDeleteTextures(1, &iter.second.Id);
		}
	}
}