#include "TaskNodeHandle.h"
#include "TaskNode.h"
#include "TaskBase.h"

using namespace Task;


/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="pParentTask">親</param>
/// <param name="pThisTask">管理するタスク</param>
/// <param name="priority">実行順</param>
TaskNodeHandle::TaskNodeHandle(TaskNodeHandle* pParentTask, TaskBase* pWorkTask, int priority)
{
	mpParentTask = pParentTask;
	mpWorkTask = pWorkTask;
	mPriority = priority;

	// 管理タスクが存在する場合はタスクハンドルを設定
	if (mpWorkTask != NULL)
	{
		mpWorkTask->SetThisTaskHandle(this);
	}

	// 親が指定されている場合はその親の子として登録
	if (pParentTask != NULL)
	{
		pParentTask->AddChildTask(this);
	}
}

/// <summary>
/// デストラクタ
/// </summary>
TaskNodeHandle::~TaskNodeHandle()
{
	// 管理タスクの削除
	if(mpWorkTask != NULL)
	{
		delete(mpWorkTask);
		mpWorkTask = NULL;
	}

	// 子の削除
	for (std::list<TaskNodeHandle*>::iterator itr = mChildTaskList.begin(); itr != mChildTaskList.end(); ++itr)
	{
		if (mpWorkTask != NULL)
		{
			delete((*itr));
			mpWorkTask = NULL;
		}
	}

	mChildTaskList.clear();
}

/// <summary>
/// 更新
/// </summary>
/// <returns>削除するかどうか true = 削除しない, false = 削除</returns>
bool TaskNodeHandle::Update()
{
	// 管理タスクが存在する場合は更新処理
	if (mpWorkTask != NULL)
	{
		// 管理タスクの更新
		bool ret = false;
		ret = mpWorkTask->Update();

		// 戻り値がfalseの場合はこの更新をせず終了
		if (!ret)
		{
			return false;
		}
	}

	// 子タスクの更新
	for (std::list<TaskNodeHandle*>::iterator itr = mChildTaskList.begin(); itr != mChildTaskList.end(); ++itr)
	{
		bool ret = false;
		ret = (*itr)->Update();

		// 戻り値がfalseなら削除
		if (!ret)
		{
			(*itr)->DeleteWarkTask();

			continue;
		}
	}

	return true;
}

/// <summary>
/// 描画
/// </summary>
void TaskNodeHandle::Draw()
{
	// 管理タスクが存在する場合は描画処理
	if (mpWorkTask != NULL)
	{
		// 描画の前処理
		mpWorkTask->DrawBegin();

		// 管理タスクの更新
		mpWorkTask->Draw();
	}

	// 子タスクの描画
	for (std::list<TaskNodeHandle*>::iterator itr = mChildTaskList.begin(); itr != mChildTaskList.end(); ++itr)
	{
		(*itr)->Draw();
	}

	if (mpWorkTask != NULL)
	{
		// 描画の後処理
		mpWorkTask->DrawEnd();
	}
}

/// <summary>
/// 子の追加
/// </summary>
/// <param name="pChild">追加する子</param>
void TaskNodeHandle::AddChildTask(TaskNodeHandle* pChild)
{
	// NULLの追加は認めない
	if (pChild == NULL)
	{
		return;
	}

	mChildTaskList.push_back(pChild);
}

/// <summary>
/// 子のソート
/// </summary>
void TaskNodeHandle::SortChild()
{
	mChildTaskList.sort(
		[](TaskNodeHandle* a, TaskNodeHandle* b)
		{
			return a->GetPrioryty() < b->GetPrioryty();
		}
	);
}

/// <summary>
/// 管理タスクのない子を削除
/// </summary>
void TaskNodeHandle::Clean()
{
	for (std::list<TaskNodeHandle*>::iterator itr = mChildTaskList.begin(); itr != mChildTaskList.end(); ++itr)
	{
		// 管理タスクがある場合
		if ((*itr)->IsWorkTask())
		{
			// 子の確認
			(*itr)->Clean();

			// 次へ
			continue;
		}

		// 管理タスクがないので削除
		delete((*itr));
		itr = mChildTaskList.erase(itr);

		// リストが末尾の場合はループを抜ける
		if (itr == mChildTaskList.end())
		{
			break;
		}
	}
}

/// <summary>
/// 管理タスクの削除
/// </summary>
void TaskNodeHandle::DeleteWarkTask()
{
	// 管理タスクが指定されていないなら処理しない
	if (mpWorkTask == NULL)
	{
		return;
	}

	// 管理タスクの削除
	delete(mpWorkTask);

	mpWorkTask = NULL;
}