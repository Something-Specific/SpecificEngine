#pragma once

#include "..\Contracts\IComponent.h"
#include <string>

namespace Gin {
	namespace ECS {

		class IdentityComponent : public IComponent {
		public:
			int Id;
			std::string *Name;

			IdentityComponent(std::string *name) {
				Id = NextAvailableId();
				Name = name;
			}

			IdentityComponent(int id, std::string *name) {
				Id = id;
				Name = name;
			}

			ComponentType GetType() {
				return ComponentType::Identity;
			}

			~IdentityComponent() {
				Name->~basic_string();
			}

		private: 
			static int CurrentId;
			inline static int NextAvailableId(){ return ++CurrentId; }
		};
	}
}