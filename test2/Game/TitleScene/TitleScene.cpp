#include "../../pch.h"
#include "WICTextureLoader.h"
#include "DDSTextureLoader.h"

#include "TitleScene.h"

#include "../DrawManager.h"

using namespace MyGame;

/// <summary>
/// �R���X�g���N�^
/// </summary>
TitleScene::TitleScene()
{
	System::DrawManager::GetInstance().LoadTexture(mDrawData, L"PressAnyKey.png");
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
TitleScene::~TitleScene()
{

}

/// <summary>
/// �X�V
/// </summary>
/// <returns></returns>
bool TitleScene::Update()
{
	return true;
}

/// <summary>
/// �`��
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