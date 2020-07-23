
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
		Resources::ResourceLoader::LoadTexture("rsc/BasicTile.png", 1, "BasicTile");
		GAME_INFO("Game initialized.");

		// auto tileTex = Resources::ResourceLoader::GetTexture("BasicTile");
		Texture = Resources::ResourceLoader::GetTexture("BasicTile");
		Position = glm::vec2(20, 20);
		Size = glm::vec2(512.0, 512.0);

		// auto sprite = new Gin::Display::Sprite(&tileTex, 100, 100, 32, 32);
		// stage->AddChild(sprite);
	}

	/*
		The update function for all game logic. This will occur at a fixed
		delta of 60 a second.
	*/
	void Game::Update(Inputs::Processor *processor, float dt)
	{
	}

	void Game::Render(Graphics::Renderer *renderer, float dt)
	{
		// stage->Render(renderer, dt);
		renderer->Render(Texture, Position, Size);
	}
} // namespace Demo