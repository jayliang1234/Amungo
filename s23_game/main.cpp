#include "Game.h"
#include <iostream>
#include<functional>


class S23_Game_App : public Game::GameApp
{
public:
	S23_Game_App()
	{
		SetKeyPressedCallback([this](const Game::KeyPressed& e) {MyKeyPressedFunc(e); });
		SetKeyReleasedCallback([this](const Game::KeyReleased& e) {MyKeyReleasedFunc(e); });
	}

	virtual void OnUpdate() override
	{
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		int randomNumber = std::rand() % 501 + 1000;
		int randomNumber2 = std::rand() % 501 + 1500;
		int randomNumber3 = std::rand() % 2001 + 2000;
		renderer.Clear();
		renderer.Draw(back, { backgroundOffset, 0 });
		renderer.Draw(instructions, { 0,429 });
		renderer.Draw(unit);
		renderer.Draw(cactus);
		renderer.Draw(cactus2);
		renderer.Draw(bird);
		renderer.Draw(bullet);
		renderer.Draw(explosion);


		//Draws the Level Number
		if (level == 1) {
			renderer.Draw(one, { x , y });
		}
		else if (level == 2) {
			renderer.Draw(two, { x , y });
		}
		else if (level == 3) {
			renderer.Draw(three, { x , y });
		}
		else if (level == 4) {
			renderer.Draw(four, { x , y });
		}
		else if (level == 5) {
			renderer.Draw(five, { x , y });
		}
		else if (level == 6) {
			renderer.Draw(six, { x , y });
		}
		else if (level == 7) {
			renderer.Draw(seven, { x , y });
		}
		else if (level == 8) {
			renderer.Draw(eight, { x , y });
		}
		else if (level == 9) {
			renderer.Draw(nine, { x , y });
		}
		else if (level == 10) {
			renderer.Draw(one, { x , y });
			renderer.Draw(zero, { x + 60 , y });
		}

		// Update the background position to simulate animated background
		backgroundOffset -= backgroundSpeed;

		// explosion moves with backgroubnd
		explosion.UpdateXCoord(-backgroundSpeed);
		// Wrap the background when it goes off-screen
		if (backgroundOffset <= -1000)
		{
			backgroundOffset = 0;
		}
		//on unit Collision with Cactus or bird
		if (UnitsOverlap(unit, cactus) || UnitsOverlap(unit, cactus2) || UnitsOverlap(unit, bird))
		{
			renderer.Draw(GameOver, {0,0});
			GameIsOver = true;
			return;
		}
		// Hold Right Key 
		if (keyRightHeld && unit.GetCoords().xCoord < width - 100 && !GameIsOver)
		{
			unit.UpdateXCoord(10);
		}
		// Hold Left key
		else if (keyLeftHeld && unit.GetCoords().xCoord > 0 && !GameIsOver)
		{
			unit.UpdateXCoord(-10);
		}
		
		// on bullet hitting bird
		if (UnitsOverlap(bullet, bird)) {
			explosion.SetCoords({ bird.GetCoords().xCoord, bird.GetCoords().yCoord });
			bird.UpdateXCoord(randomNumber3);
			bullet.SetCoords({ 1000,1000});
		}

		// Adjust gravity speed
		if (jumpHeight == 0.0f && unit.GetCoords().yCoord > 30) {
			unit.UpdateYCoord(-10);
		}

		// Adjust the character's position based on jumpHeight
		if (jumpHeight > 0.0f) {
			unit.UpdateYCoord(jumpHeight); //Simulates gravity by slowly updating by height
			jumpHeight -= 1.0f;  // Jump speed
		}

		// if unit touches the ground double jump reset
		if (unit.GetCoords().yCoord <= 30) {
			unit.SetCoords({ unit.GetCoords().xCoord, 30 });
			doubleJump = 0;
		}

		// Spawns cactus in random x coord
		if (cactus.GetCoords().xCoord  <= -50) {
			cactus.UpdateXCoord(randomNumber);
		}
		if (cactus2.GetCoords().xCoord <= -50) {
			cactus2.UpdateXCoord(randomNumber2);
		}

		// bullet moves right
		if (bullet.GetCoords().xCoord <= 1000) {
			bullet.UpdateXCoord(20);
		}
		else { //if bullet reaches end of map it disappears out of frame
			bullet.SetCoords({ 1000,1000 });
		}
		
		// If bird reaches left side it resets to a random xCoord, else cactus speed is slowly speeding up
		if (bird.GetCoords().xCoord <= -50) {
			bird.UpdateXCoord(randomNumber3);
		}
		else {
			cactus.UpdateXCoord(objectSpeed);
			cactus2.UpdateXCoord(objectSpeed);
			bird.UpdateXCoord(-15);
			//you can adjust how long each level lasts
			if (objectSpeed > -50 && frames%100 == 0) {
				objectSpeed--;
				backgroundSpeed++;
				if (abs(objectSpeed) % 5 == 0) {
					level++;
				}
			}
		}
		frames++;
	}

	void MyKeyPressedFunc(const Game::KeyPressed& e)
	{
		if (e.GetKeyCode() == GAME_KEY_RIGHT && unit.GetCoords().xCoord < width - 100 && !GameIsOver) {
			unit.UpdateXCoord(10);
			keyRightHeld = true;
		}
		else if (e.GetKeyCode() == GAME_KEY_LEFT && unit.GetCoords().xCoord > 0 && !GameIsOver) {
			unit.UpdateXCoord(-10);
			keyLeftHeld = true;
		}
		else if (((e.GetKeyCode() == GAME_KEY_SPACE && (unit.GetCoords().yCoord <= 30 || doubleJump < 2)) ) && !GameIsOver) { //Can only jump if you're on the floor
			jumpHeight = 15.0f;
			doubleJump++;
		}
		else if (e.GetKeyCode() == GAME_KEY_ENTER && GameIsOver == true) {
			GameReset();
		}
		else if (e.GetKeyCode() == GAME_KEY_LEFT_CONTROL && bullet.GetCoords().xCoord >= 1000){
			bullet.SetCoords({unit.GetCoords().xCoord+20,unit.GetCoords().yCoord+20 });
		}
	}

	void MyKeyReleasedFunc(const Game::KeyReleased& e)
	{
		if (e.GetKeyCode() == GAME_KEY_RIGHT)
		{
			keyRightHeld = false;
		}
		else if (e.GetKeyCode() == GAME_KEY_LEFT)
		{
			keyLeftHeld = false;
		}
	}

	//resets game
	void GameReset() {
		GameIsOver = false;
		jumpHeight = 0.0f;
		unit.SetCoords({ 100,30 });
		cactus.SetCoords({ 1000,30 });
		cactus2.SetCoords({ 1500,30 });
		bird.SetCoords({ 5000,150 });
		bullet.SetCoords({ 1000,1000 });
		backgroundOffset = 0;
		objectSpeed = -10;
		backgroundSpeed = 10;
		OnUpdate();
		level = 1;
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
	Game::Unit cactus2{ "../Assets/Images/cactus2.png", {1500,30} };
	Game::Unit bird{ "../Assets/Images/bird.png", {5000,150} };
	Game::Unit bullet{ "../Assets/Images/bullet.png", {1000,50} };
	Game::Unit explosion{ "../Assets/Images/explosion.png", {1000,1000} };
	Game::Image back{ "../Assets/Images/background.png" };
	Game::Image GameOver{ "../Assets/Images/gameover.png" };
	Game::Image home{ "../Assets/Images/homescreen.png" };
	Game::Image instructions{ "../Assets/Images/instructions.png" };

	Game::Image zero{ "../Assets/Images/0.png" };
	Game::Image one{ "../Assets/Images/1.png" };
	Game::Image two{ "../Assets/Images/2.png" };
	Game::Image three{ "../Assets/Images/3.png" };
	Game::Image four{ "../Assets/Images/4.png" };
	Game::Image five{ "../Assets/Images/5.png" };
	Game::Image six{ "../Assets/Images/6.png" };
	Game::Image seven{ "../Assets/Images/7.png" };
	Game::Image eight{ "../Assets/Images/8.png" };
	Game::Image nine{ "../Assets/Images/9.png" };

	int x = 500, y = 400;
	int frames = 0;
	int objectSpeed = -10;
	int doubleJump = 0;
	bool keyRightHeld = false;
	bool keyLeftHeld = false;
	int backgroundOffset = 0;
	int backgroundSpeed = 10;
	int level = 1;
};

GAME_START(S23_Game_App);