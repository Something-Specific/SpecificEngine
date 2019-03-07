
#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <map>
#include <string>
#include <GL/glew.h>

#include "../Graphics/Texture2D.h"

namespace Core 
{
	namespace Resources
	{
		class ResourceLoader
		{
		public:
			// Resource storage
			static std::map<std::string, Graphics::Texture2D> Textures;

			// Loads (and generates) a texture from file
			static Graphics::Texture2D LoadTexture(const GLchar *file, GLboolean alpha, std::string name);

			// Retrieves a stored texture
			static Graphics::Texture2D GetTexture(std::string name);


			// Retrieves a stored texture
			static void Clear();

		private:
			// Loads a single texture from file
			static Graphics::Texture2D loadTextureFromFile(const GLchar *file, GLboolean alpha);
		};
	}
}

#endif
