/////////////////////////////////////////////////////
// Name : GameBase
//
// Author : 山田 聖弥
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
// Over View : ゲームの基底クラス
/////////////////////////////////////////////////////
class GameBase
{
protected:
	//ウィンドウクラス
	std::unique_ptr<Window> window_;

	//初期化処理
	virtual void Initialize();

	//更新処理
	virtual void Update();

	//描画処理
	virtual void Render();

public:

	//コンストラクタ
	GameBase();

	//デストラクタ
	virtual ~GameBase();

	//GameBaseのメイン関数
	void Main(HINSTANCE hInstance, int nCmdShow);
};

