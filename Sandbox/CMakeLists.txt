project(Sandbox)

# Create the executable
add_executable(${PROJECT_NAME} src/Application.cpp)

target_link_libraries(${PROJECT_NAME}
    nlohmann_json::nlohmann_json
    Catch2::Catch2
	Gin::Core
)