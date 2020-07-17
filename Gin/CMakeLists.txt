
find_package(glad CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

file(GLOB_RECURSE fileCollection "src/*.cpp" "src/*.h")
add_library(Gin ${fileCollection})

target_link_libraries(Gin PRIVATE glad::glad)
target_link_libraries(Gin PRIVATE spdlog)

target_include_directories(Gin PUBLIC "src/")
