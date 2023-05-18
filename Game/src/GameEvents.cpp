#include "pch.h"
#include "GameEvents.h"

namespace Game
{
	KeyPressed::KeyPressed(int kCode) : mKeyCode(kCode)
	{

	}
	int KeyPressed::GetKeyCode() const
	{
		return mKeyCode;
	}
	KeyReleased::KeyReleased(int kCode) : mKeyCode(kCode)
	{
	}
	int KeyReleased::GetKeyCode() const
	{
		return mKeyCode;
	}
}