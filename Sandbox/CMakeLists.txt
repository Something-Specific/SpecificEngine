
# find_package(EnTT CONFIG REQUIRED)

add_executable(Sandbox 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Game.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/Game.h"
)


target_link_libraries(Sandbox PUBLIC Gin)

add_custom_command(TARGET Sandbox
          POST_BUILD
          COMMAND ${CMAKE_COMMAND} -E copy_directory 
          "${CMAKE_CURRENT_SOURCE_DIR}/rsc" 
          "$<TARGET_FILE_DIR:Sandbox>/rsc"
)