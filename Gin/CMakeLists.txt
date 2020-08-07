
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
include_directories(${DevIL_INCLUDE_DIRS})
find_package(DevIL REQUIRED)
find_package(libpng CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)

add_library(Gin 
"${CMAKE_CURRENT_SOURCE_DIR}/src/Gin.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Components/Body.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Components/Collider.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Components/Transform.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Components/Sprite.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Core/MasterGame.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Core/MasterGame.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Scene.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Core/Scene.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Renderer.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Renderer.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Screen.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Screen.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Shader.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Shader.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Texture2D.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Texture2D.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Inputs/Controller.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Inputs/Controller.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Inputs/Keyboard.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Inputs/Keyboard.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Inputs/Keys.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Inputs/Mouse.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Inputs/Mouse.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Inputs/Processor.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Inputs/Processor.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Resources/GinConfig.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Resources/ResourceLoader.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Resources/ResourceLoader.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Resources/PhysicsSystem.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Resources/PhysicsSystem.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Systems/RenderSystem.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Systems/RenderSystem.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Systems/TestSystem.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Systems/InputSystem.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Systems/InputSystem.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Utils/Assert.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Utils/Assert.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Utils/Log.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Utils/Log.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Utils/Macros.h"
)


set_target_properties(Gin PROPERTIES PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/src/Gin.h")
target_include_directories(Gin PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src" PRIVATE ${IL_INCLUDE_DIR})

target_link_libraries(Gin PUBLIC png glad::glad glfw glm nlohmann_json::nlohmann_json ${IL_LIBRARIES} spdlog::spdlog EnTT::EnTT)


target_compile_features(Gin PUBLIC cxx_std_20)