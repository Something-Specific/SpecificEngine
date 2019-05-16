
find_library(GAINPUT_PATH gainputstatic.lib ${CMAKE_CURRENT_SOURCE_DIR}/lib/.)
add_library(gainput STATIC IMPORTED GLOBAL)
message("Loading gainput from " ${GAINPUT_PATH})
set_target_properties(gainput 
	PROPERTIES 
	INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/include
	IMPORTED_LOCATION ${GAINPUT_PATH}
)
