#include "..\GinPch.h"

#include "Stage.h"

namespace Gin {
	namespace Display {

		Stage::Stage() {
			Actors = new std::list<Actor*>();
		}

		void Stage::AddChild(Actor* actor) {
			Actors->push_back(actor);
		}

		void Stage::RemoveChild(Actor* actor) {
			Actors->remove(actor);
		}

		void Stage::Update(Inputs::Processor* processor, float dt) {
			for (auto actor = Actors->begin(); actor != Actors->end(); actor++)
			{
				(*actor)->Update(processor, dt);
			}
		}

		void Stage::Render(Graphics::Renderer* renderer, float dt) {
			for (auto actor = Actors->begin(); actor != Actors->end(); actor++)
			{
				(*actor)->Render(renderer, dt);
			}
		}


		Stage::~Stage()
		{
			delete Actors;
		}

	}
}
