#pragma once
#include "pch.h"
#include "GameUtil.h"
#include "ImplImage.h"
namespace Game
{
	class GAME_API Image
	{
	public:
		Image(const std::string& imageFile);
		Image(std::string&& imageFile);

		void Activate();

		int GetWidth() const;
		int GetHeight() const;

	private:
		std::unique_ptr<ImplImage> mImplementation{ nullptr };

	};
}