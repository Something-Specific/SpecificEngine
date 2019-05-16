project(Gin VERSION 1.0.0)

set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} STATIC)
add_library(${PROJECT_NAME}::Core ALIAS ${PROJECT_NAME})

target_sources(${PROJECT_NAME} 
	PUBLIC 
		${SRC}/Gin.h
		${SRC}/GinPch.h
		${SRC}/GinPch.cpp

		${SRC}/Core/MasterGame.cpp
		${SRC}/Core/MasterGame.h

		${SRC}/ECS/Components/ComponentType.h
		${SRC}/ECS/Components/DisplayComponent.h
		${SRC}/ECS/Components/IdentityComponent.h
		${SRC}/ECS/Components/PositionComponent.h
		${SRC}/ECS/Components/RigidBodyComponent.h
		${SRC}/ECS/Components/VelocityComponent.h

		${SRC}/ECS/Contracts/IComponent.h
		${SRC}/ECS/Contracts/IEventManager.h
		${SRC}/ECS/Contracts/INode.h
		${SRC}/ECS/Contracts/IRenderableSystem.h
		${SRC}/ECS/Contracts/ISystemContext.h
		${SRC}/ECS/Contracts/IUpdateableSystem.h

		${SRC}/ECS/Nodes/Rendernode.h

		${SRC}/ECS/System/RenderSystem.cpp
		${SRC}/ECS/System/RenderSystem.h
		${SRC}/ECS/System/SystemTypes.h

		${SRC}/ECS/Engine.cpp
		${SRC}/ECS/Engine.h
		${SRC}/ECS/Entity.h
		${SRC}/ECS/Entity.cpp
		${SRC}/ECS/SystemContext.h

		${SRC}/Events/Delegate.h
		${SRC}/Events/Dispatcher.h
		${SRC}/Events/Event.h
		${SRC}/Events/EventManager.h
		${SRC}/Events/EventManager.cpp
		${SRC}/Events/EventTypes.h

		${SRC}/Graphics/Renderer.cpp
		${SRC}/Graphics/Renderer.h
		${SRC}/Graphics/Screen.cpp
		${SRC}/Graphics/Screen.h
		${SRC}/Graphics/Shader.cpp
		${SRC}/Graphics/Shader.h
		${SRC}/Graphics/Texture2D.cpp
		${SRC}/Graphics/Texture2D.h

		${SRC}/Inputs/Controller.cpp
		${SRC}/Inputs/Controller.h
		${SRC}/Inputs/Keyboard.cpp
		${SRC}/Inputs/Keyboard.h
		${SRC}/Inputs/Keys.h
		${SRC}/Inputs/Mouse.cpp
		${SRC}/Inputs/Mouse.h
		${SRC}/Inputs/Processor.cpp
		${SRC}/Inputs/Processor.h
		${SRC}/Inputs/Summoner.cpp
		${SRC}/Inputs/Summoner.h

		${SRC}/Maths/Maths.h
		${SRC}/Maths/Vector2.h

		${SRC}/Resources/GinConfig.hpp
		${SRC}/Resources/ResourceLoader.cpp
		${SRC}/Resources/ResourceLoader.h

		${SRC}/Utils/Assert.cpp
		${SRC}/Utils/Assert.h
		${SRC}/Utils/Log.cpp
		${SRC}/Utils/Log.h
		${SRC}/Utils/Macros.h

		)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
    nlohmann_json::nlohmann_json
    spdlog::spdlog
	glad
	glfw
	glm
	gainput
	soil
)


