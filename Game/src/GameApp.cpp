#include "pch.h"
#include "GameApp.h"

namespace Game
{
	void GameApp::Run()
	{
		while (true)
		{
			std::cout << "Game running \n";





			OnUpdate();
		}
	}
}
