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
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		int randomNumber = std::rand() % 501 + 1000;
		int randomNumber2 = std::rand() % 501 + 1500;
		int randomNumber3 = std::rand() % 2001 + 2000;
		renderer.Clear();
		renderer.Draw(back, { 0,0 });
		renderer.Draw(unit);
		renderer.Draw(cactus);
		renderer.Draw(cactus2);
		renderer.Draw(bird);
		renderer.Draw(laser);

		if (UnitsOverlap(unit, cactus) || UnitsOverlap(unit, cactus2) || UnitsOverlap(unit, bird)) //on collision
		{
			renderer.Draw(GameOver, {0,0});
			GameIsOver = true;
			return;
		}
		if (UnitsOverlap(laser, bird)) {
			bird.UpdateXCoord(randomNumber3);
			laser.SetCoords({ 1000,1000});
		}
		if (jumpHeight == 0.0f && unit.GetCoords().yCoord > 30) {
			unit.UpdateYCoord(-10);  // Gravity speed
		}
		if (jumpHeight > 0.0f) {
			// Adjust the character's position based on jumpHeight
			unit.UpdateYCoord(jumpHeight); //Simulates gravity by slowly updating by height
			jumpHeight -= 1.0f;  // Jump speed
		}
		if (unit.GetCoords().yCoord <= 30) {
			doubleJump = 0;
		}
		if (cactus.GetCoords().xCoord  <= -50) {
			cactus.UpdateXCoord(randomNumber);
		}
		if (cactus2.GetCoords().xCoord <= -50) {
			cactus2.UpdateXCoord(randomNumber2);
		}
		if (laser.GetCoords().xCoord <= 1000) {
			laser.UpdateXCoord(20);
		}
		else {
			laser.SetCoords({ 1000,1000 });
		}
		if (bird.GetCoords().xCoord <= -50) {
			bird.UpdateXCoord(randomNumber3);
		}
		else {
			cactus.UpdateXCoord(objectSpeed);
			cactus2.UpdateXCoord(objectSpeed);
			bird.UpdateXCoord(-15);
			if (objectSpeed > -50 && frames%1000 == 0) {
				objectSpeed--;
			}
		}
		frames++;
	}
	void MyKeyPressedFunc(const Game::KeyPressed& e)
	{
		if (e.GetKeyCode() == GAME_KEY_RIGHT && unit.GetCoords().xCoord < width - 100 && !GameIsOver) {
				unit.UpdateXCoord(20);
		}
		else if (e.GetKeyCode() == GAME_KEY_LEFT && unit.GetCoords().xCoord > 0 && !GameIsOver)
			unit.UpdateXCoord(-20);
		else if (((e.GetKeyCode() == GAME_KEY_SPACE && (unit.GetCoords().yCoord <= 30 || doubleJump < 2)) ) && !GameIsOver) { //Can only jump if you're on the floor
			jumpHeight = 15.0f;
			doubleJump++;
		}
		else if (e.GetKeyCode() == GAME_KEY_ENTER && GameIsOver == true) {
			GameReset();
		}
		else if (e.GetKeyCode() == GAME_KEY_LEFT_CONTROL && laser.GetCoords().xCoord >= 1000){
			laser.SetCoords({unit.GetCoords().xCoord+20,unit.GetCoords().yCoord+20 });
		}
	}
	void GameReset() {
		GameIsOver = false;
		jumpHeight = 0.0f;
		unit.SetCoords({ 100,30 });
		cactus.SetCoords({ 1000,30 });
		cactus2.SetCoords({ 1500,30 });
		bird.SetCoords({ 5000,150 });
		laser.SetCoords({ 1000,1000 });
		objectSpeed = -10;
		OnUpdate();
	}
private:


	float jumpHeight = 0.0f;  // Initialize the jump height to 0
	int width = Game::GameWindow::GetWidth();
	int height = Game::GameWindow::GetHeight();
	Game::Renderer renderer;
	bool HomeScreen = true;
	bool GameIsOver = false;
	Game::Unit unit{ "../Assets/Images/sprite.png", {100,30} };
	Game::Unit cactus{ "../Assets/Images/cactus.png", {1000,30} };
	Game::Unit cactus2{ "../Assets/Images/cactus.png", {1500,30} };
	Game::Unit bird{ "../Assets/Images/bird.png", {5000,150} };
	Game::Unit laser{ "../Assets/Images/laser.png", {1000,50} };
	Game::Image back{ "../Assets/Images/background.png" };
	Game::Image GameOver{ "../Assets/Images/gameover2.png" };
	Game::Image home{ "../Assets/Images/homescreen.png" };
	int frames = 0;
	int objectSpeed = -10;
	int doubleJump = 0;

};

GAME_START(S23_Game_App);