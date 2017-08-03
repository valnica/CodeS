/////////////////////////////////////////////////////
// Name : InputManager
//
// Author : �R�c ����
//
// Day : 2017/8/3
/////////////////////////////////////////////////////
#pragma once

#include <d3d11.h>
#include <SimpleMath.h>
#include <memory>
#include <Mouse.h>
#include <Keyboard.h>

#include "../Utility/Singleton/Singleton.h"

namespace Math = DirectX::SimpleMath;

/////////////////////////////////////////////////////
// Name : InputManager
//
// Over View : ���͊Ǘ��N���X
/////////////////////////////////////////////////////
class InputManager:public Singleton<InputManager>
{
private:
	//�L�[�{�[�h
	std::shared_ptr<DirectX::Keyboard> key_;
	std::shared_ptr<DirectX::Keyboard::KeyboardStateTracker> keyTracker_;

	//�}�E�X
	std::shared_ptr<DirectX::Mouse> mouse_;
	std::shared_ptr<DirectX::Mouse::ButtonStateTracker> mouseTracker_;

	friend Singleton<InputManager>;

	//�R���X�g���N�^
	InputManager();
public:

	//�f�X�g���N�^
	~InputManager();

	//����������
	void Initialize();

	//�X�V����
	void Update();

	//�E�B���h�E�̐ݒ�
	void Window(HWND window);

	//�w�肵���L�[��������Ă邩
	bool KeyInput(DirectX::Keyboard::Keys key);

	//�w�肵���L�[�������ꂽ�u�Ԃ����o
	bool KeyInputDown(DirectX::Keyboard::Keys key);

	//�}�E�X�̎擾
	DirectX::Mouse* Mouse();

	//�}�E�X�g���b�J�[�̎擾
	DirectX::Mouse::ButtonStateTracker* MouseTacker();

	//�}�E�X�̍��W�̎擾
	Math::Vector2 MousePos();
};

