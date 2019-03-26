

#include "Game.h"

namespace Demo
{
	/*
		The first thing to happen when the game enters run. This
		should be the function to load in all the assets and
		create any needed objects for the update and render methods.
	 */
	void Game::Init() 
	{
		Gin::Resources::ResourceLoader::LoadTexture("rsc/card_back.png", 0, "CardBack");
		GAME_INFO("Game initialized.");
	}
	
	/*
		The update function for all game logic. This will occur at a fixed
		delta of 60 a second.
	*/
	void Game::Update(Gin::Inputs::Processor *processor, float dt)
	{
		
	}

	void Game::Render(Gin::Graphics::Renderer *renderer, float dt) 
	{
		Gin::Graphics::Texture2D texture = Gin::Resources::ResourceLoader::GetTexture("CardBack");
		renderer->Render(texture, glm::vec2(64, 64));
	}
}