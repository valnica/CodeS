/////////////////////////////////////////////////////
// Name : Game
//
// Author : �R�c ����
//
// Date : 2017/8/3
/////////////////////////////////////////////////////
#include "Game.h"
#include "GameObject\GameObject.h"
#include "RendererManager\RendererManager.h"
#include "ResourceManager\ResourceManager.h"
#include "Component/Renderer/ModelRenderer/ModelRenderer.h"
#include "Component/Renderer/SpriteRenderer/SpriteRenderer.h"
#include "Component\Transform\Transform.h"

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
	obj_.reset(new GameObject);
	obj_->AddComponent<ModelRenderer>(ModelRenderer::Tag());
	auto modelRenderer = obj_->GetComponent<ModelRenderer>(ModelRenderer::Tag());

	if (modelRenderer)
	{
		auto transform = obj_->GetComponent<Transform>(Transform::Tag());
		if (transform)
		{
			modelRenderer->Initialize(transform, L"Resources\\CMO\\Ball.cmo");
		}
	}

	obj2_.reset(new GameObject);
	obj2_->AddComponent<SpriteRenderer>(SpriteRenderer::Tag());
	auto spriteRenderer = obj2_->GetComponent<SpriteRenderer>(SpriteRenderer::Tag());
	if (spriteRenderer)
	{
		auto transform = obj2_->GetComponent<Transform>(Transform::Tag());
		if (transform)
		{
			spriteRenderer->Initialize(transform, L"Resources\\Texture\\Mario.png");
		}
	}

	obj3_.reset(new GameObject);
	obj3_->AddComponent<SpriteRenderer>(SpriteRenderer::Tag());
	spriteRenderer = obj3_->GetComponent<SpriteRenderer>(SpriteRenderer::Tag());
	if (spriteRenderer)
	{
		auto transform = obj3_->GetComponent<Transform>(Transform::Tag());
		if (transform)
		{
			spriteRenderer->Initialize(transform, L"Resources\\Texture\\Mario2.png");
		}
		transform->Parent(obj2_->GetComponent<Transform>(Transform::Tag()));
		transform->Position(Math::Vector3(100, 100, 0));
	}

	obj2_->GetComponent<Transform>(Transform::Tag())->Position(Math::Vector3(600, 200,0));
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
	obj_->Update();
	obj2_->Update();
	obj3_->Update();

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
	RendererManager::GetInstance()->Render();

	GameBase::Render();
}