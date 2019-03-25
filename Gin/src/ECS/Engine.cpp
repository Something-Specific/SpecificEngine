#include "..\GinPch.h"

#include "Engine.h"

namespace Gin {
	namespace ECS {

		Engine::Engine() {
			UpdateSystems = new std::map<unsigned short, IUpdateableSystem*>();
			RenderSystems = new std::map<unsigned short, IRenderableSystem*>();
			Entities = new std::list<Entity*>();
		}

		Engine::~Engine() {
			UpdateSystems->clear();
			delete UpdateSystems;
			RenderSystems->clear();
			delete RenderSystems;
		}

		void Engine::Update(float dt, Processor* processor) {
			for (auto system = UpdateSystems->begin(); system != UpdateSystems->end(); ++system) {
				system->second->Update(dt, processor);
			}
		}

		void Engine::Render(float dt, Renderer* renderer) {
			for (auto system = RenderSystems->begin(); system != RenderSystems->end(); ++system) {
				system->second->Render(dt, renderer);
			}
		}

		void Engine::AddEntity(Entity *entity) {
			Entities->push_back(entity);
		}

		void Engine::AddSystem(unsigned short priority, IUpdateableSystem *system) {
			UpdateSystems->emplace(priority, system);
		}

		void Engine::AddSystem(unsigned short priority, IRenderableSystem *system) {
			RenderSystems->emplace(priority, system);
		}

	}
}