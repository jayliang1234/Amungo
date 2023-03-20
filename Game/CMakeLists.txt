set(HEADER_FILES
	src/GameUtil.h
	src/GameApp.h
	src/GameWindow.h
	src/WindowImplementation.h
	src/GLFWcode/GLFWimplementation.h
)

set(SOURCE_FILES
	src/GameApp.cpp
	src/GameWindow.cpp
	src/GLFWcode/GLFWimplementation.cpp
)
add_library(Game SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(src)

target_precompile_headers(Game PRIVATE src/pch.h)

target_link_libraries(Game glfw)

add_definitions(-DGAME_LIB)
add_definitions(-DGAME_GLFW)