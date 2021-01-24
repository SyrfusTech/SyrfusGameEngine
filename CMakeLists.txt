# Declare CMake version requirements
cmake_minimum_required(VERSION 3.1...3.19)

# Declare projcet target-name, version number, and project languages
project(
    SyrfusGameEngine
    VERSION 0.2
    LANGUAGES CXX
)

# Declare C++ standard for the project
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Setting the Game Engine as the Visual Studio startup project
set_property(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    PROPERTY VS_STARTUP_PROJECT SyrfusGameEngine
)

# GLFW docs, tests, and examples removed from compilation process
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Helps IDE's recognize what files are to be included
include(CheckIncludeFile)
include(CheckIncludeFileCXX)
include(CheckIncludeFiles)

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# include_directories(${PROJECT_BINARY_DIR}/include)

# Recursive calls to CMakeLists.txt files in the following directories
add_subdirectory(thirdParty/glfw)
add_subdirectory(thirdParty/glad)
add_subdirectory(src)

# Tell the linker to link the glfw target produced by GLFW into the main executable
target_link_libraries(SyrfusGameEngine glfw)
target_link_libraries(SyrfusGameEngine glad)

# Getting GLFW and GLAD to play nicely
target_compile_definitions(
    SyrfusGameEngine
    PUBLIC
    GLFW_INCLUDE_NONE
)