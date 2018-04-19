#include "TaskManager.h"
#include "TaskBase.h"
#include "TaskNode.h"
#include "TaskNodeHandle.h"

using namespace Task;

// �}�X�^�[�m�[�h
TaskNodeHandle TaskManager::mMasterNode(NULL, NULL, 0);

// �t���O
unsigned int TaskManager::mFlag = 0;

/// <summary>
/// �^�X�N�ǉ�
/// </summary>
/// <param name="pTask">�Ǘ�����^�X�N</param>
/// <param name="priority">���s��</param>
/// <returns>�^�X�N�n���h��</returns>
TaskHandle TaskManager::AddTask(TaskBase* pTask, int priority)
{
	// �^�X�N�m�[�h�n���h���̍쐬
	TaskNodeHandle* pNodeHandle = new TaskNodeHandle(&mMasterNode, pTask, priority);

	mMasterNode.SortChild();

	return pNodeHandle;
}

/// <summary>
/// �^�X�N�ǉ�(�e�w��)
/// </summary>
/// <param name="pParent">�e</param>
/// <param name="pTask">�Ǘ�����^�X�N</param>
/// <param name="priority">���s��</param>
/// <returns>�^�X�N�n���h��</returns>
TaskHandle TaskManager::AddTask(TaskHandle pParent, TaskBase* pTask, int priority)
{
	// �e�̎w�肪NULL�̏ꍇ�̓}�X�^�[�m�[�h��e�ɂ���
	TaskNodeHandle* p = dynamic_cast<TaskNodeHandle*>(pParent);

	if (p == NULL)
	{
		p = &mMasterNode;
	}

	// �^�X�N�m�[�h�n���h���̍쐬
	TaskNodeHandle* pNodeHandle = new TaskNodeHandle(dynamic_cast<TaskNodeHandle*>(pParent), pTask, priority);

	p->SortChild();

	return pNodeHandle;
}

/// <summary>
/// �^�X�N�폜
/// </summary>
/// <param name="hTask">�폜�������^�X�N</param>
void TaskManager::RemoveTask(TaskHandle hTask)
{
	// �L���X�g
	TaskNodeHandle* pNodeHandle = dynamic_cast<TaskNodeHandle*>(hTask);

	// �L���X�g�Ɏ��s�����珈�����Ȃ�
	if (pNodeHandle == NULL)
	{
		return;
	}

	// �Ǘ��^�X�N�̍폜
	pNodeHandle->DeleteWarkTask();

	// �폜�t���O�𗧂Ă�
	mFlag |= eTaskManagerFlag::IsDeleted;
}

/// <summary>
/// �R���X�g���N�^
/// </summary>
TaskManager::TaskManager()
{

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
TaskManager::~TaskManager()
{

}

/// <summary>
/// �X�V
/// </summary>
void TaskManager::Update()
{
	mMasterNode.Update();
}

/// <summary>
/// �`��
/// </summary>
void TaskManager::Draw()
{
	mMasterNode.Draw();
}

/// <summary>
/// �s�v�^�X�N�̍폜
/// </summary>
void TaskManager::CleanTask()
{
	// �폜�t���O�������Ă��Ȃ��ꍇ�͏������Ȃ�
	if ((mFlag & eTaskManagerFlag::IsDeleted) == 0)
	{
		return;
	}

	// �s�v�^�X�N�̍폜
	mMasterNode.Clean();

	// �폜�t���O�𕚂���
	mFlag &= ~eTaskManagerFlag::IsDeleted;
}
