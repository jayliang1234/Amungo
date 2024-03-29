#pragma once
#include "pch.h"
#include "GameUtil.h"
#include "Image.h"
#include "Shader.h"
#include "ImplRenderer.h"
#include "RendererTypes.h"
#include "Unit.h"
namespace Game
{
	class GAME_API Renderer
	{
	public:

		Renderer();

		void Draw(Image& image, Shader& shader, ScreenCoord coords);
		void Draw(Image& image, ScreenCoord coords);

		void Draw(Image& image, TextureBox texCoords, Shader& shader, ScreenCoord coords);
		void Draw(Image& image, TextureBox texCoords, ScreenCoord coords);

		void Draw(Unit& unit, Shader& shader);
		void Draw(Unit& unit);

		void Clear();

	private:
		std::unique_ptr<ImplRenderer> mImplementation{ nullptr };

		Shader mDefaultShader;

	};
}