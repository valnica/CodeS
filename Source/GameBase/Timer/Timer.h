/////////////////////////////////////////////////////
// Name : Timer
//
// Author : �R�c ����
//
// Day : 2017/8/3
/////////////////////////////////////////////////////
#pragma once

#include <Windows.h>

/////////////////////////////////////////////////////
// Name : Timer
//
// Over View : fps�^�C�}�[
/////////////////////////////////////////////////////
class Timer
{
private:
	//���g��
	LARGE_INTEGER freq_;

	//���̃t���[��
	LARGE_INTEGER now_;

	//�O�̃t���[��
	LARGE_INTEGER last_;

	//fps�̌Œ萔
	int fps_;

	//����fps���擾���邽�߂̕ϐ�
	float nowFps_;

	//�O�t���[������̌o�ߐ�
	static float deltaTime_;

public:
	//�R���X�g���N�^
	Timer(int fps);

	//�f�X�g���N�^
	~Timer();

	//�X�V����
	void Update();

	//����fps�̎擾
	float Fps();

	//�o�ߎ��Ԃ̎擾
	static float DeltaTime();
};