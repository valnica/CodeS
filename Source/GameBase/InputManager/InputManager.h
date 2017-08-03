/////////////////////////////////////////////////////
// Name : InputManager
//
// Author : 山田 聖弥
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
// Over View : 入力管理クラス
/////////////////////////////////////////////////////
class InputManager:public Singleton<InputManager>
{
private:
	//キーボード
	std::shared_ptr<DirectX::Keyboard> key_;
	std::shared_ptr<DirectX::Keyboard::KeyboardStateTracker> keyTracker_;

	//マウス
	std::shared_ptr<DirectX::Mouse> mouse_;
	std::shared_ptr<DirectX::Mouse::ButtonStateTracker> mouseTracker_;

	friend Singleton<InputManager>;

	//コンストラクタ
	InputManager();
public:

	//デストラクタ
	~InputManager();

	//初期化処理
	void Initialize();

	//更新処理
	void Update();

	//ウィンドウの設定
	void Window(HWND window);

	//指定したキーが押されてるか
	bool KeyInput(DirectX::Keyboard::Keys key);

	//指定したキーが押された瞬間を検出
	bool KeyInputDown(DirectX::Keyboard::Keys key);

	//マウスの取得
	DirectX::Mouse* Mouse();

	//マウストラッカーの取得
	DirectX::Mouse::ButtonStateTracker* MouseTacker();

	//マウスの座標の取得
	Math::Vector2 MousePos();
};

