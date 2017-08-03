/////////////////////////////////////////////////////
// Name : InputManager
//
// Author : 山田 聖弥
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
// Over View : コンストラクタ
//
// Argument : 無し
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
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
InputManager::~InputManager()
{
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : 初期化処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void InputManager::Initialize()
{
	mouse_->SetMode(DirectX::Mouse::MODE_ABSOLUTE);
	Window(Window::Handle());
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
// Over View : Windowの設定
//
// Argument : Window
//
// Return : 無し
/////////////////////////////////////////////////////
void InputManager::Window(HWND window)
{
	mouse_->SetWindow(window);
}

/////////////////////////////////////////////////////
// Name : KeyInput
//
// Over View : 指定したキーが押されてるか
//
// Argument : 判定したいキー
//
// Return : 押されていたらtrue
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
// Over View : 指定したキーが押された瞬間を検出
//
// Argument : 判定したいキー
//
// Return : 押されていたらtrue
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
// Over View : マウスの取得
//
// Argument : 無し
//
// Return : マウス
/////////////////////////////////////////////////////
DirectX::Mouse * InputManager::Mouse()
{
	return mouse_.get();
}

/////////////////////////////////////////////////////
// Name : MouseTracker
//
// Over View : マウストラッカーの取得
//
// Argument : 無し
//
// Return : マウスのトラッカー
/////////////////////////////////////////////////////
DirectX::Mouse::ButtonStateTracker* InputManager::MouseTacker()
{
	return mouseTracker_.get();
}

/////////////////////////////////////////////////////
// Name : MousePos
//
// Over View : マウスの座標の取得
//
// Argument : 無し
//
// Return : マウスの座標
/////////////////////////////////////////////////////
Math::Vector2 InputManager::MousePos()
{
	auto pos = Vector2((float)mouse_->GetState().x, (float)mouse_->GetState().y);

	return pos;
}
