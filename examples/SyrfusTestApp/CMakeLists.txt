# ----------------------------------------
# ------------Project Settings------------
# ----------------------------------------

cmake_minimum_required(VERSION 3.1)
project(
	SyrfusTestApp
	VERSION 0.0
	LANGUAGES CXX C
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ----------------------------------------
# ----------Compiler Definitions----------
# ----------------------------------------

# Nothing for now

# ----------------------------------------
# ----IDE Setup / Include directories-----
# ----------------------------------------

# Setting the Game Engine as the Visual Studio startup project
set_property(
	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
	PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME}
)

# Helps IDE's recognize what files are to be included
include(CheckIncludeFile)
include(CheckIncludeFileCXX)
include(CheckIncludeFiles)

# This takes the first file, and looks for specific flags to replace with CMake variable values (currently just a version number)
configure_file(src/SyrfusTestAppConfig.hpp.in src/SyrfusTestAppConfig.hpp)

# Compile a list of all source files
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/**.[hc]*(pp))

# Output executable compiled with target name SyrfusTestApp from the list of source files
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Make Visual Studio display the filters as the directory structure (Off for now)
# source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

# Add the src directory as include
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${PROJECT_BINARY_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../src"
    "${CMAKE_CURRENT_SOURCE_DIR}/../../include"
)

# Tell the linker to link the Game Engine library into the SyrfusTestApp executable
target_link_libraries(${PROJECT_NAME} SyrfusGameEngine)