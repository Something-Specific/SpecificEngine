#pragma once

#include "Contracts\IComponent.h"
#include "Components\ComponentType.h"
#include <map>
#include <string>

namespace Gin {
	namespace ECS {
		class Entity
		{
		public:
			Entity();
			Entity(std::string *name);
			~Entity();

			void Add(IComponent *component);
			void Remove(ComponentType type);

			bool TryGetComponent(ComponentType type, IComponent *component);

		private:
			std::map<ComponentType, IComponent*> *Components;
		};
	}
}

