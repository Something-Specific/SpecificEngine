project(Gin VERSION 1.0.0 DESCRIPTION "Very nice project")


add_library(${PROJECT_NAME} STATIC src/Gin.h)
add_library(${PROJECT_NAME}::Core ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(${PROJECT_NAME}
    INTERFACE 
        ${PROJECT_SOURCE_DIR}/src
)
target_include_directories(${PROJECT_NAME}
		PUBLIC 
		${GLAD_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    nlohmann_json::nlohmann_json
    spdlog::spdlog
	glad
	glfw
	glm
	gainputstatic
)


