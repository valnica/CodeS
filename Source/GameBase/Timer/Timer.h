/////////////////////////////////////////////////////
// Name : Timer
//
// Author : 山田 聖弥
//
// Day : 2017/8/3
/////////////////////////////////////////////////////
#pragma once

#include <Windows.h>

/////////////////////////////////////////////////////
// Name : Timer
//
// Over View : fpsタイマー
/////////////////////////////////////////////////////
class Timer
{
private:
	//周波数
	LARGE_INTEGER freq_;

	//今のフレーム
	LARGE_INTEGER now_;

	//前のフレーム
	LARGE_INTEGER last_;

	//fpsの固定数
	int fps_;

	//今のfpsを取得するための変数
	float nowFps_;

	//前フレームからの経過数
	static float deltaTime_;

public:
	//コンストラクタ
	Timer(int fps);

	//デストラクタ
	~Timer();

	//更新処理
	void Update();

	//今のfpsの取得
	float Fps();

	//経過時間の取得
	static float DeltaTime();
};