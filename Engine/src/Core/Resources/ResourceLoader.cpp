
#include "ResourceLoader.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <SOIL.h>

#include "../Graphics/Texture2D.h"

namespace Core 
{
	namespace Resources 
	{

		std::map<std::string, Graphics::Texture2D> ResourceLoader::Textures;

		Graphics::Texture2D ResourceLoader::LoadTexture(const GLchar *file, GLboolean alpha, std::string name)
		{
			Textures[name] = loadTextureFromFile(file, alpha);
			return Textures[name];
		}

		Graphics::Texture2D ResourceLoader::GetTexture(std::string name)
		{
			return Textures[name];
		}

		Graphics::Texture2D ResourceLoader::loadTextureFromFile(const GLchar *file, GLboolean alpha)
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
			unsigned char* image = SOIL_load_image(file, &width, &height, 0, texture.Image_Format == GL_RGBA ? SOIL_LOAD_RGBA : SOIL_LOAD_RGB);
			// Now generate texture
			texture.Generate(width, height, image);
			// And finally free image data
			SOIL_free_image_data(image);
			return texture;
		}

		void ResourceLoader::Clear()
		{
			for (auto iter : Textures)
				glDeleteTextures(1, &iter.second.Id);
		}
	}
}