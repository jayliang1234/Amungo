set(HEADER_FILES
	src/GameUtil.h
	src/GameApp.h
	src/GameWindow.h
	src/WindowImplementation.h
	src/GLFWcode/GLFWimplementation.h
	src/Renderer.hs
	src/ImplRenderer.h
	src/OpenGLCode/OpenGLRenderer.h
	src/RendererTypes.h
	src/Shader.h
	src/ImplShader.h
	src/OpenGLCode/OpenGLShader.h
	src/Image.h
	src/ImplImage.h
	src/OpenGLCode/OpenGLImage.h	
	
)

set(SOURCE_FILES
	src/GameApp.cpp
	src/GameWindow.cpp
	src/GLFWcode/GLFWimplementation.cpp
	src/Shader.cpp
	src/OpenGLCode/OpenGLShader.cpp
	src/Renderer.cpp
	src/OpenGLCode/OpenGLRenderer.cpp
	src/Image.cpp
	src/OpenGLCode/OpenGLImage.cpp
)
add_library(Game SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(src)
include_directories(../glad/include)
include_directories(../stbi)
include_directories(../glfw/include)

target_precompile_headers(Game PRIVATE src/pch.h)

target_link_libraries(Game glfw glad stbi)

add_definitions(-DGAME_LIB)
add_definitions(-DGAME_GLFW)
add_definitions(-DGAME_OPENGL)
add_definitions(-DGAME_WINDOWS)
add_definitions(-DFLOOR_DEBUG=2)