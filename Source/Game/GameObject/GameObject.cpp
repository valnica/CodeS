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

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

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
	transform_ = nullptr;
	component_.clear();
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
	for each(auto component in component_)
	{
		component.second->Run();
	}
}