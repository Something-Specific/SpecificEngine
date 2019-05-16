cmake_minimum_required(VERSION 3.8...3.14)

project(SpecificEngine)
set(CMAKE_CXX_STANDARD 17)


include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(Vendor)
add_subdirectory(External)
add_subdirectory(Gin)
add_subdirectory(Sandbox)