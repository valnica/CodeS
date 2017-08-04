////////////////////////////////////////////////////
// Name : Window
//
// Author : �R�c ����
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
// Over View : �R���X�g���N�^
//
// Argument : ����
////////////////////////////////////////////////////
Window::Window(HINSTANCE instanceHandle, int cmdShow)
	:instanceHandle_(instanceHandle),cmdShow_(cmdShow)
{
}

////////////////////////////////////////////////////
// Name : ~Window
//
// Over View : �f�X�g���N�^
//
// Argument : ����
////////////////////////////////////////////////////
Window::~Window()
{
}

////////////////////////////////////////////////////
// Name : ~Window
//
// Over View : �f�X�g���N�^
//
// Argument : ����
//
// Return : �쐬�ł�����True
////////////////////////////////////////////////////
bool Window::Craete(int size_x, int size_y)
{
	// �E�C���h�E�N���X��o�^����
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

	// �E�C���h�E���쐬����
	RECT rc = { 0, 0, size_x, size_y };	// ���E�C���h�E�T�C�Y
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	windowHandle_ = CreateWindow(wcex.lpszClassName, L"CodeS", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, nullptr, nullptr, instanceHandle_,
		nullptr);

	if (!windowHandle_)
		return false;

	// �E�C���h�E�̕\��
	ShowWindow(windowHandle_, cmdShow_);

	return true;
}

////////////////////////////////////////////////////
// Name : WndProc
//
// Over View : �E�B���h�E�v���V�[�W���[
//
// Argument : �E�B���h�E�n���h���A���b�Z�[�W
//            �p����
//
// Return : ����
////////////////////////////////////////////////////
LRESULT Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		// �E�C���h�E���j�����ꂽ���b�Z�[�W
	case WM_DESTROY:
		// WM_QUIT���b�Z�[�W�𑗏o����i���C�����[�v�𔲂���j
		PostQuitMessage(0);
		break;

		// �E�C���h�E���A�N�e�B�u���A��A�N�e�B�u�����鎞�ɗ��郁�b�Z�[�W
	case WM_ACTIVATEAPP:
		DirectX::Keyboard::ProcessMessage(message, wParam, lParam);
		DirectX::Mouse::ProcessMessage(message, wParam, lParam);
		break;

		// �L�[���͊֌W�̃��b�Z�[�W
	case WM_KEYDOWN:
	case WM_SYSKEYDOWN:
	case WM_KEYUP:
	case WM_SYSKEYUP:
		DirectX::Keyboard::ProcessMessage(message, wParam, lParam);
		break;

		// �}�E�X�֌W�̃��b�Z�[�W
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
		// �����ŏ������Ȃ����b�Z�[�W��DefWindowProc�֐��ɔC����
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

////////////////////////////////////////////////////
// Name : Handle
//
// Over View : �E�B���h�E�n���h���̎擾
//
// Argument : ����
//
// Return : �E�B���h�E�n���h��
////////////////////////////////////////////////////
HWND Window::Handle()
{
	return windowHandle_;
}
