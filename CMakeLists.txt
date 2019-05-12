cmake_minimum_required(VERSION 3.14)

project(SpecificEngine)


set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/out)
include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(Gin)
add_subdirectory(Vendor)
add_subdirectory(Sandbox)