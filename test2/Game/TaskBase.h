#pragma once

#include "TaskManager.h"

namespace Task
{
	class TaskBase
	{
	public:	// 基本処理

		TaskBase();

		virtual ~TaskBase();

		// 更新
		virtual bool Update() = 0;

		// 描画
		virtual void Draw() {};
		virtual void DrawBegin() {};
		virtual void DrawEnd() {};

		// タスクハンドルの設定
		void SetThisTaskHandle(TaskHandle hTask)
		{
			mhThisTask = hTask;
		}

		// タスクハンドルの取得
		TaskHandle GetThisTaskHandle()
		{
			return mhThisTask;
		}

	private:

		// タスクハンドル
		TaskHandle mhThisTask;

	private:

	};
}