# Setup Project
cmake_minimum_required(VERSION 3.1)
project(
	SyrfusGameEngine
	VERSION 0.0
	LANGUAGES CXX C
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# GLFW disable un-necessary build items
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)


# Add external dependencies
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glfw)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/glad)


# Compiler Definitions
add_compile_definitions(SYRFUS_GAME_ENGINE_OPENGL=1)
add_compile_definitions(SYRFUS_GAME_ENGINE_VULKAN=0)
add_compile_definitions(SYRFUS_GAME_ENGINE_ENGINE_LOGGING=1)
add_compile_definitions(SYRFUS_GAME_ENGINE_APP_LOGGING=1)
add_compile_definitions(SYRFUS_GAME_ENGINE_ENGINE_TIME_PROFILING=1)
add_compile_definitions(SYRFUS_GAME_ENGINE_APP_TIME_PROFILING=1)
add_compile_definitions(SYRFUS_GAME_ENGINE_ENGINE_MEMORY_PROFILING=1)
add_compile_definitions(SYRFUS_GAME_ENGINE_APP_MEMORY_PROFILING=1)


# Help IDE's recognize what files are to be included
include(CheckIncludeFile)
include(CheckIncludeFileCXX)
include(CheckIncludeFiles)


# Passes in CMake variables to the generated .hpp file
configure_file(src/SyrfusGameEngineConfig.hpp.in src/SyrfusGameEngineConfig.hpp)


# Add static library
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
	${CMAKE_CURRENT_SOURCE_DIR}/src/**.[hc]*(pp)
	${CMAKE_CURRENT_SOURCE_DIR}/include/**.[hc]*(pp)
)
add_library(${PROJECT_NAME}	STATIC)
target_sources(${PROJECT_NAME} PRIVATE
	${SOURCE_FILES}
)


# Display all project files in the Visual Studio Solution Explorer
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})


# Add include directories
target_include_directories(${PROJECT_NAME}
	PRIVATE
	# Where the library itself will look for it's internal headers
	${CMAKE_CURRENT_SOURCE_DIR}/src
	${PROJECT_BINARY_DIR}/src

	PUBLIC
	# where top-level project will look for the library's public headers
	$<BUILD_INTERFACE:
		${CMAKE_CURRENT_SOURCE_DIR}/include
		${CMAKE_CURRENT_SOURCE_DIR}/src
	>
)


# Link external dependencies
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} glad)