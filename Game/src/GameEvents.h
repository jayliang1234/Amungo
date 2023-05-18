#pragma once
#include "GameUtil.h"
namespace Game
{
	class GAME_API KeyPressed
	{
	public:
		KeyPressed(int kCode);
		int GetKeyCode() const;
	private:
		int mKeyCode;

	};

	class GAME_API KeyReleased
	{
	public:
		KeyReleased(int kCode);
		int GetKeyCode() const;


	private:
		int mKeyCode;


	};
	class GAME_API WindowClosed
	{
	};
}
