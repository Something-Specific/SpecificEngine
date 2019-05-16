cmake_minimum_required(VERSION 3.14)

project(Sandbox)

# Create the executable
add_executable(${PROJECT_NAME} src/Application.cpp)

target_link_libraries(${PROJECT_NAME}
    nlohmann_json::nlohmann_json
	Gin::Core
)