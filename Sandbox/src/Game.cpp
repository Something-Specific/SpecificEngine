
#include "Game.h"

#include <entt/entt.hpp>


namespace Demo
{
	using namespace Gin;
	using namespace ECS::Components;
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
		auto transform = Transform(glm::vec2(20, 20), glm::vec2(512, 512), 0);
		auto sprite = Sprite(tileTex);

		auto test = scene->getRegistry().create();

		scene->getRegistry().emplace<Transform>(test, transform);
		scene->getRegistry().emplace<Sprite>(test, sprite);

		// auto processor = new Inputs::Processor();
		// auto &pref = *processor;

		// Gin::ECS::Systems::InputSystem(scene->getRegistry(), pref);
	}

	/*
		The update function for all game logic. This will occur at a fixed
		delta of 60 a second.
	*/
	void Game::Update(Inputs::Processor *processor, float dt)
	{
		scene->Update(processor, dt);
	}

	void Game::Render(Graphics::Renderer *renderer, float dt)
	{
		scene->Render(renderer, dt);
	}
} // namespace Demo