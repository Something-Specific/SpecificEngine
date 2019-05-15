
#include "..\GinPch.h"

#include "Entity.h"
#include "Contracts\IComponent.h"
#include "Components\IdentityComponent.h"


namespace Gin {
	namespace ECS {


		Entity::Entity() {
			Components = new std::map<ComponentType, IComponent*>();
			Add((IComponent*)new IdentityComponent(new std::string("Default")));
		}

		Entity::Entity(std::string *name) {
			Components = new std::map<ComponentType, IComponent*>();
			Add((IComponent*)new IdentityComponent(name));
		}

		void Entity::Add(IComponent *component) {
			Components->emplace(component->GetType(), component);
		}

		void Entity::Remove(ComponentType type) {
			Components->erase(type);
		}

		bool Entity::TryGetComponent(ComponentType type, IComponent** component) {
			auto pos = Components->find(type);
			if (pos == Components->end())
				return false;
			auto s = pos->second;
			*component = (pos->second);
			return true;
		}

		Entity::~Entity()
		{
			delete Components;
		}

	}
}

