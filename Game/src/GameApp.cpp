#include "pch.h"
#include "GameApp.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include"stb_image.h"

#include "Renderer.h"
#include "Shader.h"
#include "GameWindow.h"
#include "Image.h"
namespace Game
{
	GameApp::GameApp()
	{
		GameWindow::Init();
		GameWindow::CreateWindow(1000, 600, "Amrungus");
		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });
	}
	void GameApp::Run()
	{
		mNextFrameTime = std::chrono::steady_clock::now();

		while (!mGameWindowShouldClose)
		{
			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			Game::GameWindow::SwapBuffers();
			Game::GameWindow::PollEvents();

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		}
	}
	void GameApp::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		GameWindow::GetWindow()->SetKeyPressedCallback(callbackFunc);
	}
	void GameApp::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		GameWindow::GetWindow()->SetKeyReleasedCallback(callbackFunc);
	}
	void GameApp::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		GameWindow::GetWindow()->SetWindowCloseCallback(callbackFunc);
	}
	void GameApp::DefaultWindowCloseHandler()
	{
		mGameWindowShouldClose = true;
	}
}
