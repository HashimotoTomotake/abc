#pragma once

#include "../TaskBase.h"

namespace MyGame
{
	class StartScene : public Task::TaskBase
	{
	public:

		StartScene();

		~StartScene();

		// XV
		bool Update();

	private:
	};
}