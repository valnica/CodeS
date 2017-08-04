/////////////////////////////////////////////////////
// Name : GameObject
//
// Author : �R�c ����
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#include "GameObject.h"
#include "../Component/Transform/Transform.h"
#include "../../GameBase/Graphics/Graphics.h"


/////////////////////////////////////////////////////
// Name : GameObject
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
GameObject::GameObject()
{
	AddComponent<Transform>(Transform::Tag());
	transform_ = GetComponent<Transform>(Transform::Tag());

	auto device =  Graphics::GetInstance()->Device();
	auto factory = Graphics::GetInstance()->Factory();

	model_ = DirectX::Model::CreateFromCMO(device,L"Resources\\CMO\\Ball.cmo",*factory);
}

/////////////////////////////////////////////////////
// Name : ~GameObject
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
GameObject::~GameObject()
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
void GameObject::Update()
{
	auto device = Graphics::GetInstance()->Device();
	auto context = Graphics::GetInstance()->Context();
	auto commonState = Graphics::GetInstance()->CommonState();

	for each(auto component in component_)
	{
		component.second->Run();
	}

	auto view = Math::Matrix::CreateLookAt(Math::Vector3(0, 3, 5), Math::Vector3(0, 0, 0), Math::Vector3(0, 1, 0));
	auto proj = Math::Matrix::CreatePerspectiveFieldOfView(45, 1280.0f / 720.0f, 0.1, 1000);

	model_->Draw(context, *commonState, transform_->World(), view, proj);
}