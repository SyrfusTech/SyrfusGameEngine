# This takes the first file, and looks for specific flags to replace with CMake variable values (currently just a version number)
configure_file(SyrfusGameEngineConfig.h.in SyrfusGameEngineConfig.h)

# Compile a list of cpp and h/hpp files and store them in the ENGINE_SOURCE and ENGINE_HEADERS variables
file(
    GLOB_RECURSE ENGINE_SOURCE
    CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)
file(
    GLOB_RECURSE ENGINE_HEADERS
    CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
)

# Output executable compiled with target name SyrfusGameEngine from the list of source files
add_executable(${PROJECT_NAME} ${ENGINE_HEADERS} ${ENGINE_SOURCE})

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${PROJECT_BINARY_DIR}/src"
)