set(HEADER_FILES
	src/GameUtil.h
	src/GameApp.h
)

set(SOURCE_FILES
	src/GameApp.cpp
)
add_library(Game SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DGAME_LIB)
