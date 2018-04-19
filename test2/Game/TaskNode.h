#pragma once

#include <list>

namespace Task
{

	class TaskBase;
	class TaskNodeHandle;

	class TaskNode
	{
	public:

		TaskNode();

		virtual ~TaskNode();

		int GetPrioryty();

	protected:

		// 親タスク
		TaskNodeHandle* mpParentTask;

		// 管理するタスク
		TaskBase* mpWorkTask;

		// 子のタスク
		std::list<TaskNodeHandle*> mChildTaskList;

		// 実行優先順位
		int mPriority;


	};
}