

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
		Resources::ResourceLoader::LoadTexture("rsc/BasicTile.png", 0, "BasicTile");
		GAME_INFO("Game initialized.");


		auto tileTex = Resources::ResourceLoader::GetTexture("BasicTile");

		CoreEngine->AddSystem(0, (ECS::IRenderableSystem*) new ECS::RenderSystem(CoreEngine->Context));

		auto tile = new ECS::Entity(new std::string("Tile"));
		tile->Add((ECS::IComponent*) new ECS::DisplayComponent(&tileTex));
		tile->Add((ECS::IComponent*) new ECS::PositionComponent(new Maths::Vector2f(100.0F, 10.0F)));
		tile->Add((ECS::IComponent*) new ECS::RigidbodyComponent(64, 64));

		CoreEngine->AddEntity(tile);
	}
	
	/*
		The update function for all game logic. This will occur at a fixed
		delta of 60 a second.
	*/
	void Game::Update(Inputs::Processor *processor, float dt)
	{
		CoreEngine->Update(dt, processor);
	}

	void Game::Render(Graphics::Renderer *renderer, float dt) 
	{
		CoreEngine->Render(dt, renderer);
	}
}