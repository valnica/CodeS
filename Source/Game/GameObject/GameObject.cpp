/////////////////////////////////////////////////////
// Name : GameObject
//
// Author : 山田 聖弥
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
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
GameObject::GameObject()
{
	AddComponent<Transform>(Transform::Tag());
	transform_ = GetComponent<Transform>(Transform::Tag());
}

/////////////////////////////////////////////////////
// Name : ~GameObject
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
GameObject::~GameObject()
{
	transform_ = nullptr;
	component_.clear();
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
void GameObject::Update()
{
	for each(auto component in component_)
	{
		component.second->Run();
	}
}