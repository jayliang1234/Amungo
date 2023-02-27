#pragma once

#ifdef GAME_WINDOWS
	#ifdef GAME_LIB
		#define GAME_API __declspec(dllexport)
	#else
		#define GAME_API __declspec(dllimport)
	#endif
#else
	#define GAME_API
#endif

#define GAME_START(ClassName) \
int main()\
{\
	ClassName game;\
	game.Run();\
	return 0;\
}