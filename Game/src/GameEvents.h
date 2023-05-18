#pragma once
#include "GameUtil.h"
namespace Game
{
	class GAME_API KeyPressed
	{
	public:
		KeyPressed(int kCode);
		KeyPressed() = delete;
		int GetKeyCode() const;
	private:
		int mKeyCode;

	};

	class GAME_API KeyReleased
	{
	public:
		KeyReleased(int kCode);
		KeyReleased() = delete;
		int GetKeyCode() const;


	private:
		int mKeyCode;


	};
	class GAME_API WindowClosed
	{
	};
}
