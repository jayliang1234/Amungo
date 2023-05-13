#include "Game.h"
#include <iostream>


class S23_Game_App : public Game::GameApp
{
  public:
	S23_Game_App() 
	{
		Game::GameWindow::Init();
		Game::GameWindow::CreateWindow(800, 600, "Test Name");
	}

	virtual void OnUpdate() override
	{
		
	}

};

GAME_START(S23_Game_App);