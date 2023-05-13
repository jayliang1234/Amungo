#include "pch.h"
#include "GameApp.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include"stb_image.h"

#include "Renderer.h"
#include "Shader.h"
#include "GameWindow.h"
namespace Game
{
	void GameApp::Run()
	{
		Renderer renderer;
		/*// texture

		unsigned int texture1;
		
		glGenTextures(1, &texture1);
		glBindTexture(GL_TEXTURE_2D, texture1);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load("../Assets/Images/test.png", &width, &height, &nrChannels, 0);

		if (data == nullptr)
			std::cout << "ERROR: Image reading has failed" << std::endl;

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);*/

		Image pic{"../Assets/Images/test.png"};
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
