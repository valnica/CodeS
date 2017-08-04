////////////////////////////////////////////////////
// Name : Window
//
// Author : 山田 聖弥
//
// Date : 2017/8/3
////////////////////////////////////////////////////
#include <Windows.h>
#include <Mouse.h>
#include <Keyboard.h>

#include "Window.h"

HWND Window::windowHandle_;

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

////////////////////////////////////////////////////
// Name : Window
//
// Over View : コンストラクタ
//
// Argument : 無し
////////////////////////////////////////////////////
Window::Window(HINSTANCE instanceHandle, int cmdShow)
	:instanceHandle_(instanceHandle),cmdShow_(cmdShow)
{
}

////////////////////////////////////////////////////
// Name : ~Window
//
// Over View : デストラクタ
//
// Argument : 無し
////////////////////////////////////////////////////
Window::~Window()
{
}

////////////////////////////////////////////////////
// Name : ~Window
//
// Over View : デストラクタ
//
// Argument : 無し
//
// Return : 作成できたらTrue
////////////////////////////////////////////////////
bool Window::Craete(int size_x, int size_y)
{
	// ウインドウクラスを登録する
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = instanceHandle_;
	wcex.hIcon = LoadIcon(instanceHandle_, (LPCTSTR)NULL);
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = L"WindowClass";
	wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)NULL);
	if (!RegisterClassEx(&wcex))
		return false;

	// ウインドウを作成する
	RECT rc = { 0, 0, size_x, size_y };	// ←ウインドウサイズ
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	windowHandle_ = CreateWindow(wcex.lpszClassName, L"CodeS", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, instanceHandle_,
		nullptr);

	if (!windowHandle_)
		return false;

	// ウインドウの表示
	ShowWindow(windowHandle_, cmdShow_);

	return true;
}

////////////////////////////////////////////////////
// Name : WndProc
//
// Over View : ウィンドウプロシージャー
//
// Argument : ウィンドウハンドル、メッセージ
//            パラム
//
// Return : 結果
////////////////////////////////////////////////////
LRESULT Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		// ウインドウが破棄されたメッセージ
	case WM_DESTROY:
		// WM_QUITメッセージを送出する（メインループを抜ける）
		PostQuitMessage(0);
		break;

		// ウインドウがアクティブ化、非アクティブ化する時に来るメッセージ
	case WM_ACTIVATEAPP:
		DirectX::Keyboard::ProcessMessage(message, wParam, lParam);
		DirectX::Mouse::ProcessMessage(message, wParam, lParam);
		break;

		// キー入力関係のメッセージ
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
	case WM_KEYUP:
	case WM_SYSKEYUP:
		DirectX::Keyboard::ProcessMessage(message, wParam, lParam);
		break;

		// マウス関係のメッセージ
	case WM_INPUT:
	case WM_MOUSEMOVE:
	case WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
	case WM_RBUTTONDOWN:
	case WM_RBUTTONUP:
	case WM_MBUTTONDOWN:
	case WM_MBUTTONUP:
	case WM_MOUSEWHEEL:
	case WM_XBUTTONDOWN:
	case WM_XBUTTONUP:
	case WM_MOUSEHOVER:
		DirectX::Mouse::ProcessMessage(message, wParam, lParam);
		break;

	default:
		// 自分で処理しないメッセージはDefWindowProc関数に任せる
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

////////////////////////////////////////////////////
// Name : Handle
//
// Over View : ウィンドウハンドルの取得
//
// Argument : 無し
//
// Return : ウィンドウハンドル
////////////////////////////////////////////////////
HWND Window::Handle()
{
	return windowHandle_;
}
