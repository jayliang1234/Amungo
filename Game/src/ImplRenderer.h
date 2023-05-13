#pragma once
#include "Renderer.h"
#include "RendererTypes.h"
namespace Game
{
	class ImplRenderer
	{
	public:
		virtual void Draw(Image& image, 
			TextureBox texCoords,
			Shader& shader,
			ScreenCoord coords) = 0;
		virtual void Clear() = 0;
	};
}
