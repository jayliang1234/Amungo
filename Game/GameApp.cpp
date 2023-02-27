#include "src/GameApp.h"
#include <iostream>
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

