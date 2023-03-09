cmake_minimum_required(VERSION 3.24)

project(MY_GAME)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DGAME_WINDOWS)
elseif(APPLE)
	add_definitions(-DGAME_MAC)
else()
	add_definitions(-DGAME_LINUX)
endif()

add_subdirectory(Game)
add_subdirectory(s23_game)
add_subdirectory(glfw)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT s23_game)
