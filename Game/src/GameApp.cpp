#include "pch.h"
#include "GameApp.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include"stb_image.h"
namespace Game
{
	void GameApp::Run()
	{
		while (true)
		{
			OnUpdate();
		}
	}
}
