# Declare CMake version requirements
cmake_minimum_required(VERSION 3.1...3.19)

# Declare projcet target-name, version number, and project languages
project(
    SyrfusGameEngine
    VERSION 0.1
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

# Actual directories the compiler looks at for header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${PROJECT_BINARY_DIR}/include)

# Recursive calls to CMakeLists.txt files in the following directories
add_subdirectory(include)
add_subdirectory(thirdParty/glfw)
add_subdirectory(src)

# Tell the linker to link the glfw target produced by GLFW into the main executable
target_link_libraries(SyrfusGameEngine glfw)

# Temporary until a more appropriate OpenGL loader is used (Glad most likely)
find_package(OpenGL REQUIRED)
target_link_libraries(SyrfusGameEngine OpenGL::GL)