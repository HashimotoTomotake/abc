#pragma once

#include "TaskNode.h"

namespace Task
{
	class TaskNodeHandle : public TaskNode
	{
	public:
		TaskNodeHandle(TaskNodeHandle* pParentTask, TaskBase* pWorkTask, int priority);

		~TaskNodeHandle();

		// 更新
		bool Update();

		// 描画
		void Draw();

		// 子の追加
		void AddChildTask(TaskNodeHandle* pChild);

		void SortChild();

		// 管理タスクが無い子タスクを削除
		void Clean();

		// 管理タスクの削除
		void DeleteWarkTask();

		// 管理タスクが存在するか確認
		bool IsWorkTask()
		{
			return mpWorkTask != NULL;
		}
	};
}