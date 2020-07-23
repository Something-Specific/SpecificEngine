
#include "Game.h"

namespace Demo
{
	using namespace Gin;
	/*
		The first thing to happen when the game enters run. This
		should be the function to load in all the assets and
		create any needed objects for the update and render methods.
	 */

	void Game::Init()
	{
		Resources::ResourceLoader::LoadTexture("rsc/BasicTile.png", 1, "BasicTile");
		GAME_INFO("Game initialized.");

		auto tileTex = Resources::ResourceLoader::GetTexture("BasicTile");

		// entt::entity test = Scene->Registry.create();
		// Scene->Registry.emplace<Gin::Components::Transform>(test, glm::vec2(20, 20), glm::vec2(512, 512), 0);
		// Scene->Registry.emplace<Gin::Components::Sprite>(test, tileTex);
	}

	/*
		The update function for all game logic. This will occur at a fixed
		delta of 60 a second.
	*/
	void Game::Update(Inputs::Processor *processor, float dt)
	{
		// Scene->Update(processor, dt);
	}

	void Game::Render(Graphics::Renderer *renderer, float dt)
	{
		// Scene->Update(processor, dt);
	}
} // namespace Demo