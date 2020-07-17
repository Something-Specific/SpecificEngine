
find_package(spdlog CONFIG REQUIRED)


file(GLOB_RECURSE fileCollection "src/*.cpp")
add_executable(Sandbox ${fileCollection})


target_link_libraries(Sandbox PRIVATE Gin)
target_link_libraries(Sandbox PRIVATE spdlog::spdlog)


