/////////////////////////////////////////////////////
// Name : Renderer
//
// Author : �R�c ����
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#pragma once
#include <d3d11.h>
#include <SimpleMath.h>
#include "../Component.h"

class Transform;

namespace Math = DirectX::SimpleMath;

/////////////////////////////////////////////////////
// Name : Renderer
//
// Over View : �`��̊��N���X
/////////////////////////////////////////////////////
class Renderer:public Component
{
protected:
	Transform* transform_;

public:
	Renderer();
	~Renderer();

	virtual void Initialize(Transform* transform);
	virtual void Run() override;
	virtual void Render(Math::Matrix view, Math::Matrix proj) = 0;
};

