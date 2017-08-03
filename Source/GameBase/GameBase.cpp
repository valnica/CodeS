/////////////////////////////////////////////////////
// Name : GameBase
//
// Author : �R�c ����
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
// Over View : ����������
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void GameBase::Initialize()
{
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : �X�V����
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void GameBase::Update()
{
}

/////////////////////////////////////////////////////
// Name : Render
//
// Over View : �`�揈��
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void GameBase::Render()
{
}

/////////////////////////////////////////////////////
// Name : GameBase
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
GameBase::GameBase()
{
}

/////////////////////////////////////////////////////
// Name : ~GameBase
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
GameBase::~GameBase()
{
}

/////////////////////////////////////////////////////
// Name : Main
//
// Over View : �Q�[���̃��C���֐�
//
// Argument : �Q�[�����񂷂̂ɕK�v�ȕϐ��S��
//
// Return :  ����
//////////////////////////////////////////////////////
void GameBase::Main(HINSTANCE instanceHandle, int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	//fps�Ǘ��N���X
	std::unique_ptr<Timer> timer;
	timer.reset(new Timer(60));

	//�E�B���h�E�N���X
	std::shared_ptr<Window> window_;
	window_.reset(new Window(instanceHandle, nCmdShow)); 

	// �E�C���h�E�̍쐬
	if (!window_->Craete(1280, 720))
		return;

	// DirectX�f�o�C�X�̏�����
	if (!Graphics::GetInstance()->CreateDevice(window_->Handle()))
		return;

	//����������
	Initialize();

	DirectX::SpriteFont* spriteFont = new DirectX::SpriteFont(Graphics::GetInstance()->Device(), L"myfile.spritefont");

	// ���C�����[�v
	MSG msg = { 0 };
	while (WM_QUIT != msg.message)
	{
		// ���b�Z�[�W�����Ă��邩���ׂ�
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			// ���b�Z�[�W�����Ă���΃E�C���h�E�v���V�[�W���֑���
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//�^�C�}�[�̍X�V(wait)���s��
			timer->Update();

			auto fps = timer->Fps();

			wchar_t buf[32];
			swprintf_s(buf, 16, L"fps = %f", fps);
			wchar_t buf2[32];
			swprintf_s(buf2, 32, L"fps = %f", Timer::DeltaTime());

			//���͂̍X�V
			InputManager::GetInstance()->Update();

			//�X�V����
			Update();

			//�o�b�t�@�̃N���A
			Graphics::GetInstance()->ClearBuffer();

			//�`�揈��
			Render();

			Graphics::GetInstance()->SpriteBatch()->Begin(DirectX::SpriteSortMode_BackToFront, Graphics::GetInstance()->CommonState()->NonPremultiplied(), Graphics::GetInstance()->CommonState()->PointClamp());
			// fps�̕\��
			spriteFont->DrawString(Graphics::GetInstance()->SpriteBatch().get(), buf, DirectX::SimpleMath::Vector2(0, 0));
			spriteFont->DrawString(Graphics::GetInstance()->SpriteBatch().get(), buf2, DirectX::SimpleMath::Vector2(0, 20));
			Graphics::GetInstance()->SpriteBatch()->End();

			// �o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�����ւ���
			Graphics::GetInstance()->Present();

			//�Q�[���I������
			if (InputManager::GetInstance()->KeyInputDown(DirectX::Keyboard::Escape))
			{
				msg.message = WM_QUIT;
			}
		}
	}

	delete spriteFont;
}