#pragma once

#include <list>

namespace Task
{
	class TaskBase;
	class TaskNode;
	class TaskNodeHandle;

	typedef TaskNode* TaskHandle;

	// タスクマネージャーのフラグ一覧
	enum eTaskManagerFlag
	{
		IsDeleted = (1<<0),	// 管理タスクの削除が行われたかのフラグ
	};

	class TaskManager
	{
	public:

		TaskManager();

		~TaskManager();

		// 更新
		void Update();

		// 描画
		void Draw();

		// 不要タスクの削除
		void CleanTask();

	public:	// タスク管理関数

		// タスク追加
		static TaskHandle AddTask(TaskBase* pTask, int priority = 0);

		// タスク追加(親指定)
		static TaskHandle AddTask(TaskHandle pParent, TaskBase* pTask, int priority = 0);

		// タスク削除
		static void RemoveTask(TaskHandle hTask);


	private:

		// タスクノードの根幹
		static TaskNodeHandle mMasterNode;

		// フラグ
		static unsigned int mFlag;

	};
}