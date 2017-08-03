/////////////////////////////////////////////////////
// Name : Timer
//
// Author : 山田 聖弥
//
// Day : 2017/8/3
/////////////////////////////////////////////////////
#include "Timer.h"

float Timer::deltaTime_ = 0.0f;

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

/////////////////////////////////////////////////////
// Name : Timer
//
// Over View : コンストラクタ
//
// Argument : 最大フレームレート
/////////////////////////////////////////////////////
Timer::Timer(int fps)
	:fps_(fps),nowFps_(0)
{
	// 高分解能パフォーマンスカウンタの周波数を取得
	QueryPerformanceFrequency(&freq_);
	now_ = freq_;
	last_ = freq_;
}

/////////////////////////////////////////////////////
// Name : ~Timer
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Timer::~Timer()
{
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : 更新処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void Timer::Update()
{
	//今の時間の取得
	QueryPerformanceCounter(&now_);

	deltaTime_ = (float)(now_.QuadPart - last_.QuadPart) / (float)freq_.QuadPart;

	//経過時間がfpsより少なければwaitかける
	if (deltaTime_ < 1.0f / fps_)
	{
		DWORD waitTime = (DWORD)((1.0f / fps_ - deltaTime_) * 1000);

		timeBeginPeriod(1);
		Sleep(waitTime);
		timeEndPeriod(1);

		auto dt = deltaTime_;

		//経過時間再計算
		LARGE_INTEGER now;
		QueryPerformanceCounter(&now);
		deltaTime_ = (float)(now.QuadPart - last_.QuadPart) / (float)freq_.QuadPart;

		return;
	}

	//fpsの計算
	if (deltaTime_ > 0.0f)
	{
		nowFps_ = (fps_ * 0.9999f) + (0.0001f / deltaTime_);
	}

	last_ = now_;
}

/////////////////////////////////////////////////////
// Name : Fps
//
// Over View : 今のFPSの取得
//
// Argument : 無し
//
// Return : FPS
/////////////////////////////////////////////////////
float Timer::Fps()
{
	return nowFps_;
}

/////////////////////////////////////////////////////
// Name : DeltaTime
//
// Over View : 前フレームからの経過時間の取得
//
// Argument : 無し
//
// Return : 前フレームからの経過時間
/////////////////////////////////////////////////////
float Timer::DeltaTime()
{
	return deltaTime_;
}
