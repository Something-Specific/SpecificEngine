
# find_package(gainput CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(soil CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

add_library(Gin 
"${CMAKE_CURRENT_SOURCE_DIR}/src/Gin.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Core/MasterGame.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Core/MasterGame.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Display/Actor.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Display/Actor.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Display/Sprite.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Display/Sprite.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Display/Stage.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Display/Stage.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Events/Event.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Events/EventDispatcher.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Events/EventDispatcher.h"
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
"${CMAKE_CURRENT_SOURCE_DIR}/src/Inputs/Summoner.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Inputs/Summoner.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Maths/Maths.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Maths/Vector2.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Resources/GinConfig.hpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Resources/ResourceLoader.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Resources/ResourceLoader.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Utils/Assert.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Utils/Assert.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Utils/Log.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Utils/Log.h"
"${CMAKE_CURRENT_SOURCE_DIR}/src/Utils/Macros.h"
)

set_target_properties(Gin PROPERTIES PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/src/Gin.h")
target_include_directories(Gin PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(Gin PUBLIC gainput glad glfw3 glm nlohmann_json soil spdlog)


