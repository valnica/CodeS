/////////////////////////////////////////////////////
// Name : Timer
//
// Author : �R�c ����
//
// Day : 2017/8/3
/////////////////////////////////////////////////////
#include "Timer.h"

float Timer::deltaTime_ = 0.0f;

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

/////////////////////////////////////////////////////
// Name : Timer
//
// Over View : �R���X�g���N�^
//
// Argument : �ő�t���[�����[�g
/////////////////////////////////////////////////////
Timer::Timer(int fps)
	:fps_(fps),nowFps_(0)
{
	// ������\�p�t�H�[�}���X�J�E���^�̎��g�����擾
	QueryPerformanceFrequency(&freq_);
	now_ = freq_;
	last_ = freq_;
}

/////////////////////////////////////////////////////
// Name : ~Timer
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Timer::~Timer()
{
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : �X�V����
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void Timer::Update()
{
	//���̎��Ԃ̎擾
	QueryPerformanceCounter(&now_);

	deltaTime_ = (float)(now_.QuadPart - last_.QuadPart) / (float)freq_.QuadPart;

	//�o�ߎ��Ԃ�fps��菭�Ȃ����wait������
	if (deltaTime_ < 1.0f / fps_)
	{
		DWORD waitTime = (DWORD)((1.0f / fps_ - deltaTime_) * 1000);

		timeBeginPeriod(1);
		Sleep(waitTime);
		timeEndPeriod(1);

		auto dt = deltaTime_;

		//�o�ߎ��ԍČv�Z
		LARGE_INTEGER now;
		QueryPerformanceCounter(&now);
		deltaTime_ = (float)(now.QuadPart - last_.QuadPart) / (float)freq_.QuadPart;

		return;
	}

	//fps�̌v�Z
	if (deltaTime_ > 0.0f)
	{
		nowFps_ = (fps_ * 0.9999f) + (0.0001f / deltaTime_);
	}

	last_ = now_;
}

/////////////////////////////////////////////////////
// Name : Fps
//
// Over View : ����FPS�̎擾
//
// Argument : ����
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
// Over View : �O�t���[������̌o�ߎ��Ԃ̎擾
//
// Argument : ����
//
// Return : �O�t���[������̌o�ߎ���
/////////////////////////////////////////////////////
float Timer::DeltaTime()
{
	return deltaTime_;
}
