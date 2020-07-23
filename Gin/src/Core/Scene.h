#pragma once
#include <entt/entt.hpp>

namespace Gin::Core {
    class Scene {
        public:
            entt::registry& getRegistry();        
        private:
            entt::registry registry;
    };
}