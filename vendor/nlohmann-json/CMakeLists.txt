
# Set the project name
project (nlohmann)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::json ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}
)
