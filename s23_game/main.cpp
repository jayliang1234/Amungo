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
		renderer.Draw(cactus);
		if (unit.GetCoords().xCoord == cactus.GetCoords().xCoord && unit.GetCoords().yCoord == cactus.GetCoords().yCoord) {
			renderer.Draw(GameOver, {0,0});
			GameIsOver = true;
			return;
		}
		if (jumpHeight == 0.0f && unit.GetCoords().yCoord > 30) {
			unit.UpdateYCoord(-10);  // Adjust the gravity value as desired
		}

		// Update the character's vertical position during the jump
		if (jumpHeight > 0.0f) {
			// Adjust the character's position based on jumpHeight
			unit.UpdateYCoord(jumpHeight);

			// Reduce jumpHeight over time to simulate descent
			jumpHeight -= 1.0f;  // Adjust the jump speed as desired
		}
		if (cactus.GetCoords().xCoord == -50) {
			cactus.UpdateXCoord(1000);
		}
		else {
			cactus.UpdateXCoord(-10);
		}
	}
	void MyKeyPressedFunc(const Game::KeyPressed& e)
	{
		if (e.GetKeyCode() == GAME_KEY_RIGHT && unit.GetCoords().xCoord < width - 100) {
			unit.UpdateXCoord(50);
		}
		else if (e.GetKeyCode() == GAME_KEY_LEFT && unit.GetCoords().xCoord > 0)
			unit.UpdateXCoord(-50);
		else if (e.GetKeyCode() == GAME_KEY_SPACE && unit.GetCoords().yCoord == 30) {
			// Initiate the jump motion
			unit.UpdateYCoord(20);
			jumpHeight = 15.0f;  // Adjust the jump height as desired
		}
		else if (e.GetKeyCode() == GAME_KEY_ENTER && GameIsOver == true) {
			GameReset();
		}
	}
	void GameReset() {
		unit.SetCoords({ 100,30 });
		cactus.SetCoords({ 800,30 });
		OnUpdate();
	}
private:
	float jumpHeight = 0.0f;  // Initialize the jump height to 0
	int width = Game::GameWindow::GetWidth();
	int height = Game::GameWindow::GetHeight();
	Game::Renderer renderer;
	Game::Image GameOver{ "../Assets/Images/gameover.png" };
	bool GameIsOver = false;
	Game::Unit unit{ "../Assets/Images/sprite.png", {100,30} };
	Game::Unit cactus{ "../Assets/Images/cactus.png", {800,30} };
	Game::Image back{ "../Assets/Images/background.png" };

};

GAME_START(S23_Game_App);