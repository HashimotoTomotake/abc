#include "StartScene.h"

#include "../TitleScene/TitleScene.h"

using namespace MyGame;

/// <summary>
/// �R���X�g���N�^
/// </summary>
StartScene::StartScene()
{
	// �^�C�g���V�[���^�X�N��ǉ�
	TitleScene* pTitle = new TitleScene();
	Task::TaskManager::AddTask(pTitle, 2);
	Task::TaskManager::AddTask(pTitle, 0);
	Task::TaskManager::AddTask(pTitle, 1);
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
StartScene::~StartScene()
{

}

/// <summary>
/// �X�V
/// </summary>
/// <returns></returns>
bool StartScene::Update()
{
	// ���^�X�N�̍폜
	return false;
}