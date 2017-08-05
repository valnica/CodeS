/////////////////////////////////////////////////////
// Name : Game
//
// Author : �R�c ����
//
// Date : 2017/8/3
/////////////////////////////////////////////////////
#include "Game.h"
#include "ResourceManager\ResourceManager.h"
#include "GameObject/Camera/Camera.h"
#include "../GameBase/Window/Window.h"
#include "Scene\Scene.h"
#include "Scene\PlayScene\PlayScene.h"

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

/////////////////////////////////////////////////////
// Name : Game
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Game::Game()
{
	scene_.reset(new PlayScene);
}

/////////////////////////////////////////////////////
// Name : ~Game
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Game::~Game()
{
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : ����������
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void Game::Initialize()
{
	GameBase::Initialize();

	ResourceManager::GetInstance()->Initialize();

	scene_->Initialize();

	auto window = Window::Handle();
	RECT rc;
	GetWindowRect(window,&rc);

	camera_.reset(new Camera);
	camera_->Initialize(Math::Vector3(0.0f,0.0f,5.0f),Math::Vector3(0.0f, 1.0f, 0.0f), 45, rc.right - rc.left, rc.bottom - rc.top, 0.1f, 1000);
	camera_->Main(camera_);
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : �X�V����
//
// Argument : ����
//
// Return :  ����
/////////////////////////////////////////////////////
void Game::Update()
{
	auto scene = scene_->Input();

	if (scene)
	{
		scene->Initialize();
		scene_ = scene;
	}

	scene_->Update();

	camera_->Update();

	GameBase::Update();
}

/////////////////////////////////////////////////////
// Name : Render
//
// Over View : �`�揈��
//
// Argument : ����
//
// Return :  ����
/////////////////////////////////////////////////////
void Game::Render()
{
	scene_->Render();

	GameBase::Render();
}