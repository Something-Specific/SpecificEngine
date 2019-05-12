project(Sandbox)

# Create the executable
add_executable(${PROJECT_NAME} src/Application.cpp)

target_link_libraries(${PROJECT_NAME}
    nlohmann::json
    Catch::Test
	Gin::Core
)