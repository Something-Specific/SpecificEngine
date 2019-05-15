project(Gin VERSION 1.0.0)


file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB HEADER_FILES ${PROJECT_SOURCE_DIR}/src/*.h)

add_library(${PROJECT_NAME} STATIC)
add_library(${PROJECT_NAME}::Core ALIAS ${PROJECT_NAME})

target_sources(${PROJECT_NAME} 
	PUBLIC 
		${CMAKE_CURRENT_SOURCE_DIR}/src/Gin.h
	PRIVATE
		${SRC_FILES}
		${HEADER_FILES}
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
)


