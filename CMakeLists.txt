cmake_minimum_required(VERSION 3.17.0)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake
  CACHE STRING "Vcpkg toolchain file")

project(SpecificEngine)
add_subdirectory(Gin)
add_subdirectory(Sandbox)