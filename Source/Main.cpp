/////////////////////////////////////////////////////
// Class Name : Main
//
// Author : �R�c ����
//
// Date : 2017/1/10
/////////////////////////////////////////////////////
#include "GameBase/GameBase.h"
#include "Game/Game.h"

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

/////////////////////////////////////////////////////
// Name : WinMain
//
// Over View : ���C��
//
// Argument : 
//
// Return : �I�����
/////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	std::unique_ptr<GameBase> gameMain;
	gameMain.reset(new Game);

	gameMain->Main(hInstance, nCmdShow);

	return 0;
}