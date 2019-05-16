include(ExternalProject)

ExternalProject_Add(soil_external 
	DOWNLOAD_COMMAND ""
	CONFIGURE_COMMAND ""
	BUILD_COMMAND cmake --build .
	INSTALL_COMMAND ""
	SOURCE_DIR ${EXTERNAL_SOURCE_DIR}/soil
	BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib
	INSTALL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

ExternalProject_Get_property(soil_external SOURCE_DIR)
message("Source dir of soil_external = ${SOURCE_DIR}")