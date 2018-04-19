#pragma once

#include "Keyboard.h"

#include "../TaskBase.h"
#include "../DrawManager.h"

namespace MyGame
{
	class TitleScene : public Task::TaskBase
	{
	public:

		TitleScene();

		~TitleScene();

		// çXêV
		bool Update();

		// ï`âÊ
		void Draw();
		void DrawBegin();
		void DrawEnd();

	private:

		System::DrawData mDrawData;
	};
}