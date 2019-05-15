cmake_minimum_required(VERSION 3.14)

project(SpecificEngine)

include_directories(${PROJECT_SOURCE_DIR})

add_subdirectory(Gin)
add_subdirectory(Vendor)
add_subdirectory(Sandbox)