#pragma once
#include "pch.h"
#include"GameUtil.h"
#include "Image.h"
#include "Shader.h"
#include "ImplRenderer.h"
namespace Game
{
	class GAME_API Renderer
	{
	public:

		Renderer();
		
		struct TextureBox
		{
			int xTexCoord{ 0 };
			int yTexCoord{ 0 };
			int texWidth{ 0 };
			int texHeight{ 0 };

			TextureBox(int xOnPicture, int yOnPicture, int boxWidth, int boxHeight) :
				xTexCoord(xOnPicture), yTexCoord(yOnPicture), texWidth(boxWidth), texHeight(boxHeight) {};
		};

		struct ScreenCoord
		{
			int xCoord{ 0 };
			int yCoord{ 0 };

			ScreenCoord(int x, int y) : xCoord(x), yCoord(y) {};
		};
		void Draw(Image& image, Shader& shader, ScreenCoord coords);
		void Draw(Image& image, ScreenCoord coords);

		void Draw(Image& image, TextureBox texCoords, Shader& shader, ScreenCoord coords);
		void Draw(Image& image, TextureBox texCoords, ScreenCoord coords);

	private:
		std::unique_ptr<ImplRenderer> mImplementation{ nullptr };

		Shader mDefaultShader{ "../Assets/Shaders/DefaultVertexShader.glsl",
			"../Assets/Shaders/DefaultFragmentShader.glsl" };

	};
}