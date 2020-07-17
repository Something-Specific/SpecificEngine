
file(GLOB_RECURSE fileCollection "src/*.cpp")
add_executable(Sandbox ${fileCollection})

target_link_libraries(Sandbox PUBLIC Gin)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
