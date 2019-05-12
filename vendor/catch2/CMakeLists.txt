# Set the project name
project (Catch2)

add_library(${PROJECT_NAME} INTERFACE)
add_library(Catch::Test ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    INTERFACE
        ${PROJECT_SOURCE_DIR}
)
