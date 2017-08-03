/////////////////////////////////////////////////////
// Name : Window
//
// Author : 山田 聖弥
//
// Day : 2017/8/3
/////////////////////////////////////////////////////
#pragma once

/////////////////////////////////////////////////////
// Name : Window
//
// Over View : ウィンドウクラス
/////////////////////////////////////////////////////
class Window
{
private:
	HINSTANCE instanceHandle_;
	static HWND windowHandle_;
	int cmdShow_;

public:

	//コンストラクタ
	Window(HINSTANCE instanceHandle,int cmdShow);

	//デストラクタ
	~Window();

	//Windowの作成
	bool Craete(int size_x,int size_y);

	//ウィンドウプロシージャー
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	static HWND Handle();
};