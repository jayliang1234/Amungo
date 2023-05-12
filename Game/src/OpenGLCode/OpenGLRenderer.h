#pragma once
#include"ImplRenderer.h"

namespace Game
{
	class OpenGLRenderer : public ImplRenderer
	{
	public:
		OpenGLRenderer();

		virtual void Draw(Image& image,
			Renderer::TextureBox texCoords,
			Shader& shader,
			Renderer::ScreenCoord coords) override;

	private:
		unsigned int mVBO, mVAO, mEBO;

	};
}