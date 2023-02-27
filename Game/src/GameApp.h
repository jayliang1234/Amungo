#pragma once
#include "GameUtil.h"
namespace Game
{
	class GAME_API GameApp
	{
	public:
		virtual void OnUpdate() = 0;

		void Run();



	private:




	};
}