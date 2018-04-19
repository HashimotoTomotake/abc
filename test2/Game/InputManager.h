#pragma once

#include <Mouse.h>

#include "Utility\SingletonBase.h"

namespace System
{
	class InputManager : public Utility::SingletonBase<InputManager>
	{
	public:

		friend Utility::SingletonBase<InputManager>;

	private:

		InputManager();

	public:

		// マウスの状態取得
		DirectX::Mouse::State GetMouseState();

		// Trackerの取得
		DirectX::Mouse::ButtonStateTracker GetTracker();

		// 更新
		void Update();

	private:

		// マウス
		std::unique_ptr<DirectX::Mouse> mpMouse;

		// Tracker
		DirectX::Mouse::ButtonStateTracker mTracker;
	};
}