cmake_minimum_required(VERSION 3.0.0)
project(Sandbox VERSION 0.1.0)

include(CTest)
enable_testing()


file(GLOB_RECURSE fileCollection "src/*.cpp")
add_executable(Sandbox ${fileCollection})

target_link_libraries(Sandbox Gin)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
