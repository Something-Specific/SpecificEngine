
find_package(glad CONFIG REQUIRED)

file(GLOB_RECURSE fileCollection "src/*.cpp")
add_library(Gin ${fileCollection})

set_target_properties(Gin PROPERTIES PUBLIC_HEADER "src/Gin.h")

target_link_libraries(Gin PRIVATE glad::glad)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
