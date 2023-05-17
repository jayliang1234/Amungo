#pragma once

#include "../ImplImage.h"
#include "pch.h"

namespace Game
{
	class OpenGLImage : public ImplImage
	{
	public:
		OpenGLImage(const std::string& imgFile);
		OpenGLImage(std::string&& imgFile);

		virtual void Activate() override;

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

		~OpenGLImage();
		
	private:
		unsigned int mImage{ 0 };
		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}