#include "Game.h"
#include <iostream>


class S23_Game_App : public Game::GameApp
{
  public:
	virtual void OnUpdate() override
	{
		std::cout << "Game is running" << std::endl;
	}

};

GAME_START(S23_Game_App);