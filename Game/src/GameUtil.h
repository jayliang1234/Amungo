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

#if GAME_DEBUG==2
	#define GAME_LOG(x) std::clog<<"Log: "<<x<<std:endl;
	#define GAME_ERROR(x) std::cerr<<"ERROR: "<<x<<std:endl;
#elif GAME_DEBUG==1
	#define GAME_LOG(x)
	#define GAME_ERROR(x) std::cerr<<"ERROR: "<<x<< std:endl;
#else
	#define GAME_LOG(x)
	#define GAME_ERROR(x)
#endif
