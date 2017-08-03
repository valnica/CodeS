/////////////////////////////////////////////////////
// Name : InputManager
//
// Author : �R�c ����
//
// Day : 2017/7/7
/////////////////////////////////////////////////////
#include "InputManager.h"
#include "../Window/Window.h"

using namespace Math;

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

/////////////////////////////////////////////////////
// Name : InputManager
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
InputManager::InputManager()
{
	key_.reset(new DirectX::Keyboard);
	keyTracker_.reset(new DirectX::Keyboard::KeyboardStateTracker);

	mouse_.reset(new DirectX::Mouse);
	mouseTracker_.reset(new DirectX::Mouse::ButtonStateTracker);
}

/////////////////////////////////////////////////////
// Name : ~InputManager
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
InputManager::~InputManager()
{
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : ����������
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void InputManager::Initialize()
{
	mouse_->SetMode(DirectX::Mouse::MODE_ABSOLUTE);
	Window(Window::Handle());
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
void InputManager::Update()
{
	keyTracker_->Update(key_->GetState());
	mouseTracker_->Update(mouse_->GetState());

	if (mouse_->GetState().x > 0)
	{
		int a = 0;
	}
}

/////////////////////////////////////////////////////
// Name : Window
//
// Over View : Window�̐ݒ�
//
// Argument : Window
//
// Return : ����
/////////////////////////////////////////////////////
void InputManager::Window(HWND window)
{
	mouse_->SetWindow(window);
}

/////////////////////////////////////////////////////
// Name : KeyInput
//
// Over View : �w�肵���L�[��������Ă邩
//
// Argument : ���肵�����L�[
//
// Return : ������Ă�����true
/////////////////////////////////////////////////////
bool InputManager::KeyInput(DirectX::Keyboard::Keys key)
{
	if (key_->GetState().IsKeyDown(key))
	{
		return true;
	}

	return false;
}

/////////////////////////////////////////////////////
// Name : KeyInputDown
//
// Over View : �w�肵���L�[�������ꂽ�u�Ԃ����o
//
// Argument : ���肵�����L�[
//
// Return : ������Ă�����true
/////////////////////////////////////////////////////
bool InputManager::KeyInputDown(DirectX::Keyboard::Keys key)
{
	if (keyTracker_->IsKeyPressed(key))
	{
		return true;
	}

	return false;
}

/////////////////////////////////////////////////////
// Name : Mouse
//
// Over View : �}�E�X�̎擾
//
// Argument : ����
//
// Return : �}�E�X
/////////////////////////////////////////////////////
DirectX::Mouse * InputManager::Mouse()
{
	return mouse_.get();
}

/////////////////////////////////////////////////////
// Name : MouseTracker
//
// Over View : �}�E�X�g���b�J�[�̎擾
//
// Argument : ����
//
// Return : �}�E�X�̃g���b�J�[
/////////////////////////////////////////////////////
DirectX::Mouse::ButtonStateTracker* InputManager::MouseTacker()
{
	return mouseTracker_.get();
}

/////////////////////////////////////////////////////
// Name : MousePos
//
// Over View : �}�E�X�̍��W�̎擾
//
// Argument : ����
//
// Return : �}�E�X�̍��W
/////////////////////////////////////////////////////
Math::Vector2 InputManager::MousePos()
{
	auto pos = Vector2((float)mouse_->GetState().x, (float)mouse_->GetState().y);

	return pos;
}
