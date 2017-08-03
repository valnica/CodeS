/////////////////////////////////////////////////////
// Name : GameBase
//
// Author : 山田 聖弥
//
// Day : 2017/8/3
/////////////////////////////////////////////////////
#include "GameBase.h"
#include "../Game/Game.h"
#include "Window\Window.h"
#include "../GameBase/Graphics/Graphics.h"
#include "Timer\Timer.h"
#include "InputManager\InputManager.h"

#include <SpriteFont.h>

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : 初期化処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void GameBase::Initialize()
{
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
void GameBase::Update()
{
}

/////////////////////////////////////////////////////
// Name : Render
//
// Over View : 描画処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void GameBase::Render()
{
}

/////////////////////////////////////////////////////
// Name : GameBase
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
GameBase::GameBase()
{
}

/////////////////////////////////////////////////////
// Name : ~GameBase
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
GameBase::~GameBase()
{
}

/////////////////////////////////////////////////////
// Name : Main
//
// Over View : ゲームのメイン関数
//
// Argument : ゲームを回すのに必要な変数４つ
//
// Return :  無し
//////////////////////////////////////////////////////
void GameBase::Main(HINSTANCE instanceHandle, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	//fps管理クラス
	std::unique_ptr<Timer> timer;
	timer.reset(new Timer(60));

	//ウィンドウクラス
	std::shared_ptr<Window> window_;
	window_.reset(new Window(instanceHandle, nCmdShow)); 

	// ウインドウの作成
	if (!window_->Craete(1280, 720))
		return;

	// DirectXデバイスの初期化
	if (!Graphics::GetInstance()->CreateDevice(window_->Handle()))
		return;

	//初期化処理
	Initialize();

	DirectX::SpriteFont* spriteFont = new DirectX::SpriteFont(Graphics::GetInstance()->Device(), L"myfile.spritefont");

	// メインループ
	MSG msg = { 0 };
	while (WM_QUIT != msg.message)
	{
		// メッセージが来ているか調べる
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			// メッセージが来ていればウインドウプロシージャへ送る
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//タイマーの更新(wait)も行う
			timer->Update();

			auto fps = timer->Fps();

			wchar_t buf[32];
			swprintf_s(buf, 16, L"fps = %f", fps);
			wchar_t buf2[32];
			swprintf_s(buf2, 32, L"fps = %f", Timer::DeltaTime());

			//入力の更新
			InputManager::GetInstance()->Update();

			//更新処理
			Update();

			//バッファのクリア
			Graphics::GetInstance()->ClearBuffer();

			//描画処理
			Render();

			Graphics::GetInstance()->SpriteBatch()->Begin(DirectX::SpriteSortMode_BackToFront, Graphics::GetInstance()->CommonState()->NonPremultiplied(), Graphics::GetInstance()->CommonState()->PointClamp());
			// fpsの表示
			spriteFont->DrawString(Graphics::GetInstance()->SpriteBatch().get(), buf, DirectX::SimpleMath::Vector2(0, 0));
			spriteFont->DrawString(Graphics::GetInstance()->SpriteBatch().get(), buf2, DirectX::SimpleMath::Vector2(0, 20));
			Graphics::GetInstance()->SpriteBatch()->End();

			// バックバッファとフロントバッファを入れ替える
			Graphics::GetInstance()->Present();

			//ゲーム終了処理
			if (InputManager::GetInstance()->KeyInputDown(DirectX::Keyboard::Escape))
			{
				msg.message = WM_QUIT;
			}
		}
	}

	delete spriteFont;
}