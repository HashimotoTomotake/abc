#include "TaskManager.h"
#include "TaskBase.h"
#include "TaskNode.h"
#include "TaskNodeHandle.h"

using namespace Task;

// マスターノード
TaskNodeHandle TaskManager::mMasterNode(NULL, NULL, 0);

// フラグ
unsigned int TaskManager::mFlag = 0;

/// <summary>
/// タスク追加
/// </summary>
/// <param name="pTask">管理するタスク</param>
/// <param name="priority">実行順</param>
/// <returns>タスクハンドル</returns>
TaskHandle TaskManager::AddTask(TaskBase* pTask, int priority)
{
	// タスクノードハンドルの作成
	TaskNodeHandle* pNodeHandle = new TaskNodeHandle(&mMasterNode, pTask, priority);

	mMasterNode.SortChild();

	return pNodeHandle;
}

/// <summary>
/// タスク追加(親指定)
/// </summary>
/// <param name="pParent">親</param>
/// <param name="pTask">管理するタスク</param>
/// <param name="priority">実行順</param>
/// <returns>タスクハンドル</returns>
TaskHandle TaskManager::AddTask(TaskHandle pParent, TaskBase* pTask, int priority)
{
	// 親の指定がNULLの場合はマスターノードを親にする
	TaskNodeHandle* p = dynamic_cast<TaskNodeHandle*>(pParent);

	if (p == NULL)
	{
		p = &mMasterNode;
	}

	// タスクノードハンドルの作成
	TaskNodeHandle* pNodeHandle = new TaskNodeHandle(dynamic_cast<TaskNodeHandle*>(pParent), pTask, priority);

	p->SortChild();

	return pNodeHandle;
}

/// <summary>
/// タスク削除
/// </summary>
/// <param name="hTask">削除したいタスク</param>
void TaskManager::RemoveTask(TaskHandle hTask)
{
	// キャスト
	TaskNodeHandle* pNodeHandle = dynamic_cast<TaskNodeHandle*>(hTask);

	// キャストに失敗したら処理しない
	if (pNodeHandle == NULL)
	{
		return;
	}

	// 管理タスクの削除
	pNodeHandle->DeleteWarkTask();

	// 削除フラグを立てる
	mFlag |= eTaskManagerFlag::IsDeleted;
}

/// <summary>
/// コンストラクタ
/// </summary>
TaskManager::TaskManager()
{

}

/// <summary>
/// デストラクタ
/// </summary>
TaskManager::~TaskManager()
{

}

/// <summary>
/// 更新
/// </summary>
void TaskManager::Update()
{
	mMasterNode.Update();
}

/// <summary>
/// 描画
/// </summary>
void TaskManager::Draw()
{
	mMasterNode.Draw();
}

/// <summary>
/// 不要タスクの削除
/// </summary>
void TaskManager::CleanTask()
{
	// 削除フラグが立っていない場合は処理しない
	if ((mFlag & eTaskManagerFlag::IsDeleted) == 0)
	{
		return;
	}

	// 不要タスクの削除
	mMasterNode.Clean();

	// 削除フラグを伏せる
	mFlag &= ~eTaskManagerFlag::IsDeleted;
}
