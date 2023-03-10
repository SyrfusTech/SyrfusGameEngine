# Setup Project
cmake_minimum_required(VERSION 3.1)
project(
	glad
	VERSION 0.0
	LANGUAGES CXX C
)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


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
	${CMAKE_CURRENT_SOURCE_DIR}/include

	PUBLIC
	# where top-level project will look for the library's public headers
	$<BUILD_INTERFACE:
		${CMAKE_CURRENT_SOURCE_DIR}/include
	>
)