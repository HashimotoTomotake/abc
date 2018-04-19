#include "InputManager.h"


/// <summary>
/// �R���X�g���N�^
/// </summary>
System::InputManager::InputManager()
{
	mpMouse = std::make_unique<DirectX::Mouse>();
}

/// <summary>
/// �}�E�X�̓��͏�Ԃ̎擾
/// </summary>
/// <returns>���͏��</returns>
DirectX::Mouse::State System::InputManager::GetMouseState()
{
	return mpMouse->GetState();
}

/// <summary>
/// Tracker�̎擾
/// </summary>
/// <returns>Tracker</returns>
DirectX::Mouse::ButtonStateTracker System::InputManager::GetTracker()
{
	return mTracker;
}

/// <summary>
/// �X�V����
/// </summary>
void System::InputManager::Update()
{
	DirectX::Mouse::State state = GetMouseState();
	mTracker.Update(state);
}