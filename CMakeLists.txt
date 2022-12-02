# ----------------------------------------
# ------------Project Settings------------
# ----------------------------------------

cmake_minimum_required(VERSION 3.1)
project(
	SyrfusGameEngine
	VERSION 0.0
	LANGUAGES CXX C
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# ----------------------------------------
# ----------Compiler Definitions----------
# ----------------------------------------

add_compile_definitions(SYRFUS_WINDOWS=1)
add_compile_definitions(SYRFUS_LINUX=0)
add_compile_definitions(SYRFUS_MAC=0)

add_compile_definitions(SYRFUS_OPENGL=1)
add_compile_definitions(SYRFUS_VULKAN=0)
add_compile_definitions(SYRFUS_DIRECTX=0)
add_compile_definitions(SYRFUS_METAL=0)

add_compile_definitions(SYRFUS_EGNEINE_LOGGING=1)
add_compile_definitions(SYRFUS_APP_LOGGING=1)

add_compile_definitions(SYRFUS_ENGINE_TIME_PROFILING=1)
add_compile_definitions(SYRFUS_APP_TIME_PROFILING=1)

add_compile_definitions(SYRFUS_ENGINE_MEMORY_PROFILING=1)
add_compile_definitions(SYRFUS_APP_MEMORY_PROFILING=1)

# ----------------------------------------
# ----IDE Setup / Include directories-----
# ----------------------------------------

# Helps IDE's recognize what files are to be included
include(CheckIncludeFile)
include(CheckIncludeFileCXX)
include(CheckIncludeFiles)

# Passes in CMake variables to the generated .hpp file
configure_file(src/SyrfusGameEngineConfig.hpp.in src/SyrfusGameEngineConfig.hpp)

# Compile a list of all source files
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/**.[hc]*(pp) include/**.[hc]*(pp))

# Output library with target name SyrfusGameEngine using every .hpp and .cpp file globbed above
add_library(${PROJECT_NAME} ${SOURCE_FILES})

# Add the src directory as include
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})

# Add all files in the src directory (including the SyrfusGameEngineConfig.hpp) as include
target_include_directories(
	${PROJECT_NAME}
	PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/src"
	"${PROJECT_BINARY_DIR}/src"
)

# Proecompile headers
# target_precompile_headers(
#     ${PROJECT_NAME}
#     PUBLIC
#         <iostream>
#         <sstream>
#         <string>
# 
#         <algorithm>
#         <functional>
#         <memory>
#         <utility>
#         <thread>
#         <chrono>
# 
#         <array>
#         <map>
#         <queue>
#         <set>
#         <stack>
#         <unordered_map>
#         <unordered_set>
#         <vector>
# )

# Continue CMake execution into the testing Application
add_subdirectory(examples/SyrfusTestApp)