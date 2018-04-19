#include "TaskNodeHandle.h"
#include "TaskNode.h"
#include "TaskBase.h"

using namespace Task;


/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="pParentTask">�e</param>
/// <param name="pThisTask">�Ǘ�����^�X�N</param>
/// <param name="priority">���s��</param>
TaskNodeHandle::TaskNodeHandle(TaskNodeHandle* pParentTask, TaskBase* pWorkTask, int priority)
{
	mpParentTask = pParentTask;
	mpWorkTask = pWorkTask;
	mPriority = priority;

	// �Ǘ��^�X�N�����݂���ꍇ�̓^�X�N�n���h����ݒ�
	if (mpWorkTask != NULL)
	{
		mpWorkTask->SetThisTaskHandle(this);
	}

	// �e���w�肳��Ă���ꍇ�͂��̐e�̎q�Ƃ��ēo�^
	if (pParentTask != NULL)
	{
		pParentTask->AddChildTask(this);
	}
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
TaskNodeHandle::~TaskNodeHandle()
{
	// �Ǘ��^�X�N�̍폜
	if(mpWorkTask != NULL)
	{
		delete(mpWorkTask);
		mpWorkTask = NULL;
	}

	// �q�̍폜
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
/// �X�V
/// </summary>
/// <returns>�폜���邩�ǂ��� true = �폜���Ȃ�, false = �폜</returns>
bool TaskNodeHandle::Update()
{
	// �Ǘ��^�X�N�����݂���ꍇ�͍X�V����
	if (mpWorkTask != NULL)
	{
		// �Ǘ��^�X�N�̍X�V
		bool ret = false;
		ret = mpWorkTask->Update();

		// �߂�l��false�̏ꍇ�͂��̍X�V�������I��
		if (!ret)
		{
			return false;
		}
	}

	// �q�^�X�N�̍X�V
	for (std::list<TaskNodeHandle*>::iterator itr = mChildTaskList.begin(); itr != mChildTaskList.end(); ++itr)
	{
		bool ret = false;
		ret = (*itr)->Update();

		// �߂�l��false�Ȃ�폜
		if (!ret)
		{
			(*itr)->DeleteWarkTask();

			continue;
		}
	}

	return true;
}

/// <summary>
/// �`��
/// </summary>
void TaskNodeHandle::Draw()
{
	// �Ǘ��^�X�N�����݂���ꍇ�͕`�揈��
	if (mpWorkTask != NULL)
	{
		// �`��̑O����
		mpWorkTask->DrawBegin();

		// �Ǘ��^�X�N�̍X�V
		mpWorkTask->Draw();
	}

	// �q�^�X�N�̕`��
	for (std::list<TaskNodeHandle*>::iterator itr = mChildTaskList.begin(); itr != mChildTaskList.end(); ++itr)
	{
		(*itr)->Draw();
	}

	if (mpWorkTask != NULL)
	{
		// �`��̌㏈��
		mpWorkTask->DrawEnd();
	}
}

/// <summary>
/// �q�̒ǉ�
/// </summary>
/// <param name="pChild">�ǉ�����q</param>
void TaskNodeHandle::AddChildTask(TaskNodeHandle* pChild)
{
	// NULL�̒ǉ��͔F�߂Ȃ�
	if (pChild == NULL)
	{
		return;
	}

	mChildTaskList.push_back(pChild);
}

/// <summary>
/// �q�̃\�[�g
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
/// �Ǘ��^�X�N�̂Ȃ��q���폜
/// </summary>
void TaskNodeHandle::Clean()
{
	for (std::list<TaskNodeHandle*>::iterator itr = mChildTaskList.begin(); itr != mChildTaskList.end(); ++itr)
	{
		// �Ǘ��^�X�N������ꍇ
		if ((*itr)->IsWorkTask())
		{
			// �q�̊m�F
			(*itr)->Clean();

			// ����
			continue;
		}

		// �Ǘ��^�X�N���Ȃ��̂ō폜
		delete((*itr));
		itr = mChildTaskList.erase(itr);

		// ���X�g�������̏ꍇ�̓��[�v�𔲂���
		if (itr == mChildTaskList.end())
		{
			break;
		}
	}
}

/// <summary>
/// �Ǘ��^�X�N�̍폜
/// </summary>
void TaskNodeHandle::DeleteWarkTask()
{
	// �Ǘ��^�X�N���w�肳��Ă��Ȃ��Ȃ珈�����Ȃ�
	if (mpWorkTask == NULL)
	{
		return;
	}

	// �Ǘ��^�X�N�̍폜
	delete(mpWorkTask);

	mpWorkTask = NULL;
}