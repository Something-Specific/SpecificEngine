file(GLOB_RECURSE fileCollection "src/*.cpp")
add_executable(Sandbox ${fileCollection})

target_link_libraries(Sandbox PUBLIC Gin)

add_custom_command(TARGET Sandbox
          POST_BUILD
          COMMAND ${CMAKE_COMMAND} -E copy_directory 
          "${CMAKE_CURRENT_SOURCE_DIR}/rsc" 
          "$<TARGET_FILE_DIR:Sandbox>/rsc"
)