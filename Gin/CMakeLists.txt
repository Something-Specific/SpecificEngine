project(Gin)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::Core ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    INTERFACE 
        ${PROJECT_SOURCE_DIR}/src
)

target_link_libraries(${PROJECT_NAME}
    INTERFACE nlohmann::json
    spdlog::spdlog
)