file(GLOB_RECURSE fileCollection "src/*.cpp")
add_executable(Sandbox ${fileCollection})

target_link_libraries(Sandbox PUBLIC Gin)

FILE(COPY "${CMAKE_CURRENT_SOURCE_DIR}/rsc" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

