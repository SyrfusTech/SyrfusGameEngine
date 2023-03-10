# Setup Project
cmake_minimum_required(VERSION 3.1)
project(
    SyrfusTestApp
    VERSION 0.0
    LANGUAGES CXX C
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Set Visual Studio Startup Project
set_property(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT SyrfusTestApp
)


# Add Libraries
add_subdirectory(SyrfusGameEngine)


# Helps IDE's recognize what files are to be included
include(CheckIncludeFile)
include(CheckIncludeFileCXX)
include(CheckIncludeFiles)


# Passes in CMake variables to the generated .hpp file
configure_file(SyrfusTestApp/src/SyrfusTestAppConfig.hpp.in SyrfusTestApp/src/SyrfusTestAppConfig.hpp)


# Add excecutable
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/SyrfusTestApp/src/**.[hc]*(pp))
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
	${SOURCE_FILES}
)


# Display all project files in the Visual Studio Solution Explorer
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SOURCE_FILES})


# Link libraries
target_link_libraries(${PROJECT_NAME} SyrfusGameEngine)