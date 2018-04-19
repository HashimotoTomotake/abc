#include "StartScene.h"

#include "../TitleScene/TitleScene.h"

using namespace MyGame;

/// <summary>
/// コンストラクタ
/// </summary>
StartScene::StartScene()
{
	// タイトルシーンタスクを追加
	TitleScene* pTitle = new TitleScene();
	Task::TaskManager::AddTask(pTitle, 2);
	Task::TaskManager::AddTask(pTitle, 0);
	Task::TaskManager::AddTask(pTitle, 1);
}

/// <summary>
/// デストラクタ
/// </summary>
StartScene::~StartScene()
{

}

/// <summary>
/// 更新
/// </summary>
/// <returns></returns>
bool StartScene::Update()
{
	// 自タスクの削除
	return false;
}