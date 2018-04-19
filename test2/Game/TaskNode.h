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

		// �e�^�X�N
		TaskNodeHandle* mpParentTask;

		// �Ǘ�����^�X�N
		TaskBase* mpWorkTask;

		// �q�̃^�X�N
		std::list<TaskNodeHandle*> mChildTaskList;

		// ���s�D�揇��
		int mPriority;


	};
}