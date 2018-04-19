#pragma once

#include "TaskNode.h"

namespace Task
{
	class TaskNodeHandle : public TaskNode
	{
	public:
		TaskNodeHandle(TaskNodeHandle* pParentTask, TaskBase* pWorkTask, int priority);

		~TaskNodeHandle();

		// �X�V
		bool Update();

		// �`��
		void Draw();

		// �q�̒ǉ�
		void AddChildTask(TaskNodeHandle* pChild);

		void SortChild();

		// �Ǘ��^�X�N�������q�^�X�N���폜
		void Clean();

		// �Ǘ��^�X�N�̍폜
		void DeleteWarkTask();

		// �Ǘ��^�X�N�����݂��邩�m�F
		bool IsWorkTask()
		{
			return mpWorkTask != NULL;
		}
	};
}