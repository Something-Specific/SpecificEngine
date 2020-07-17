


file(GLOB_RECURSE fileCollection "src/*.cpp")
add_executable(Sandbox ${fileCollection})
target_link_libraries(Sandbox PUBLIC Gin)



