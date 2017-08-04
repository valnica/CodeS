/////////////////////////////////////////////////////
// Name : GameBase
//
// Author : �R�c ����
//
// Day : 2017/8/3
/////////////////////////////////////////////////////
#pragma once

#include <memory>
#include <Windows.h>

class Window;

/////////////////////////////////////////////////////
// Name : GameBase
//
// Over View : �Q�[���̊��N���X
/////////////////////////////////////////////////////
class GameBase
{
protected:
	//�E�B���h�E�N���X
	std::unique_ptr<Window> window_;

	//����������
	virtual void Initialize();

	//�X�V����
	virtual void Update();

	//�`�揈��
	virtual void Render();

public:

	//�R���X�g���N�^
	GameBase();

	//�f�X�g���N�^
	virtual ~GameBase();

	//GameBase�̃��C���֐�
	void Main(HINSTANCE hInstance, int nCmdShow);
};

