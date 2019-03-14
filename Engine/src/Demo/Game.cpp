

#include "Game.h"
#include "../Core/Resources/ResourceLoader.h"

namespace Demo
{
	/*
		The first thing to happen when the game enters run. This
		should be the function to load in all the assets and
		create any needed objects for the update and render methods.
	 */
	void Game::Init() 
	{
		Core::Resources::ResourceLoader::LoadTexture("rsc/card_back.png", 0, "CardBack");
	}
	
	/*
		The update function for all game logic. This will occur approximately 60
	*/
	void Game::Update(float dt) 
	{
		
	}

	void Game::Render(Core::Graphics::Renderer *renderer) 
	{
		Core::Graphics::Texture2D texture = Core::Resources::ResourceLoader::GetTexture("CardBack");
		renderer->Render(texture, glm::vec2(64, 64));
	}
}