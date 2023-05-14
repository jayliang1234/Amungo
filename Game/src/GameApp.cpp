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
	void GameApp::Run()
	{
		Renderer renderer;

		Image pic{ "../Assets/Images/test.png" };
		pic.Activate();

		Shader sProgram{ "../Assets/Shaders/DefaultVertexShader.glsl",
			"../Assets/Shaders/DefaultFragmentShader.glsl" };

		sProgram.Pass2FloatValues("screenSize:", GameWindow::GetWidth(), GameWindow::GetHeight());

		mNextFrameTime = std::chrono::steady_clock::now();

		while (true)
		{
			renderer.Clear();

			renderer.Draw(pic, { 200, 100 });

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
}
