/////////////////////////////////////////////////////
// Name : Window
//
// Author : �R�c ����
//
// Day : 2017/8/3
/////////////////////////////////////////////////////
#pragma once

/////////////////////////////////////////////////////
// Name : Window
//
// Over View : �E�B���h�E�N���X
/////////////////////////////////////////////////////
class Window
{
private:
	HINSTANCE instanceHandle_;
	static HWND windowHandle_;
	int cmdShow_;

public:

	//�R���X�g���N�^
	Window(HINSTANCE instanceHandle,int cmdShow);

	//�f�X�g���N�^
	~Window();

	//Window�̍쐬
	bool Craete(int size_x,int size_y);

	//�E�B���h�E�v���V�[�W���[
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	static HWND Handle();
};