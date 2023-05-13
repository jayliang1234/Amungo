#pragma once

#include "pch.h"
#include "../ImplImage.h"

namespace Game
{
	class OpenGLImage : public ImplImage
	{
	public:
		OpenGLImage(const std::string& imgFile);
		OpenGLImage(std::string&& imgFile);

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Activate() override;

		~OpenGLImage();
		
	private:
		unsigned int mImage{ 0 };
		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}