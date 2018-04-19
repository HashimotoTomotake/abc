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

		// �X�V
		bool Update();

		// �`��
		void Draw();
		void DrawBegin();
		void DrawEnd();

	private:

		System::DrawData mDrawData;
	};
}