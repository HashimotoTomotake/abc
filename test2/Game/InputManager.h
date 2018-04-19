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

		// �}�E�X�̏�Ԏ擾
		DirectX::Mouse::State GetMouseState();

		// Tracker�̎擾
		DirectX::Mouse::ButtonStateTracker GetTracker();

		// �X�V
		void Update();

	private:

		// �}�E�X
		std::unique_ptr<DirectX::Mouse> mpMouse;

		// Tracker
		DirectX::Mouse::ButtonStateTracker mTracker;
	};
}