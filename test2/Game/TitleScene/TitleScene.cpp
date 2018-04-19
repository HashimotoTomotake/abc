#include "../../pch.h"
#include "WICTextureLoader.h"
#include "DDSTextureLoader.h"

#include "TitleScene.h"

#include "../DrawManager.h"

using namespace MyGame;

/// <summary>
/// コンストラクタ
/// </summary>
TitleScene::TitleScene()
{
	System::DrawManager::GetInstance().LoadTexture(mDrawData, L"PressAnyKey.png");
}

/// <summary>
/// デストラクタ
/// </summary>
TitleScene::~TitleScene()
{

}

/// <summary>
/// 更新
/// </summary>
/// <returns></returns>
bool TitleScene::Update()
{
	return true;
}

/// <summary>
/// 描画
/// </summary>
void TitleScene::Draw()
{
	System::DrawManager::GetInstance().Draw(mDrawData);
}
void TitleScene::DrawBegin()
{
	System::DrawManager::GetInstance().Begin();
}
void TitleScene::DrawEnd()
{
	System::DrawManager::GetInstance().End();
}