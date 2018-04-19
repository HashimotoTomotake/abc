#include "InputManager.h"


/// <summary>
/// コンストラクタ
/// </summary>
System::InputManager::InputManager()
{
	mpMouse = std::make_unique<DirectX::Mouse>();
}

/// <summary>
/// マウスの入力状態の取得
/// </summary>
/// <returns>入力状態</returns>
DirectX::Mouse::State System::InputManager::GetMouseState()
{
	return mpMouse->GetState();
}

/// <summary>
/// Trackerの取得
/// </summary>
/// <returns>Tracker</returns>
DirectX::Mouse::ButtonStateTracker System::InputManager::GetTracker()
{
	return mTracker;
}

/// <summary>
/// 更新処理
/// </summary>
void System::InputManager::Update()
{
	DirectX::Mouse::State state = GetMouseState();
	mTracker.Update(state);
}