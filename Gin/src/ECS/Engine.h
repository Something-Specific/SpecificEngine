#pragma once

#include <map>
#include "Contracts\IRenderableSystem.h"
#include "Contracts\IUpdateablesystem.h"
#include "SystemContext.h"
#include "..\Graphics\Renderer.h"
#include "..\Inputs\Processor.h"
#include "Entity.h"

namespace Gin {
	namespace ECS {

		using namespace Graphics;
		using namespace Inputs;

		class Engine {

		public:
			SystemContext* Context;

			Engine(SystemContext* context);
			~Engine();

			void Update(float dt, Processor* processor);
			void Render(float dt, Renderer* renderer);
			
			void AddEntity(Entity *entity);
			void AddSystem(unsigned short priority, IUpdateableSystem *system);
			void AddSystem(unsigned short priority, IRenderableSystem *system);

		private:
			std::map<unsigned short, IUpdateableSystem*> *UpdateSystems;
			std::map<unsigned short, IRenderableSystem*> *RenderSystems;
			std::list<Entity*> *Entities;
		};
	}
}