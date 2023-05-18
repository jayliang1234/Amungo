#include "Game.h"
#include <iostream>
#include<functional>


class S23_Game_App : public Game::GameApp
{
public:
	S23_Game_App()
	{
		SetKeyPressedCallback([this](const Game::KeyPressed& e) {MyKeyPressedFunc(e); });
	}

	virtual void OnUpdate() override
	{
		renderer.Clear();
		renderer.Draw(back, { 0,0 });
		renderer.Draw(unit);
	}
	void MyKeyPressedFunc(const Game::KeyPressed& e)
	{
		if (e.GetKeyCode() == GAME_KEY_RIGHT)
			unit.UpdateXCoord(20);
		else if (e.GetKeyCode() == GAME_KEY_LEFT)
			unit.UpdateXCoord(-20);
	}
private:
	Game::Renderer renderer;
	Game::Unit unit{ "../Assets/Images/test1.png", {100,100} };
	Game::Image back{ "../Assets/Images/back1.png" };

};

GAME_START(S23_Game_App);