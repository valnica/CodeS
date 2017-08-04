/////////////////////////////////////////////////////
// Name : SpriteRenderer
//
// Author : �R�c ����
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#pragma once

#include <d3d11.h>
#include <string>
#include "../Renderer.h"

/////////////////////////////////////////////////////
// Name : SpriteRenderer
//
// Over View : �摜�̃����_���[�N���X
/////////////////////////////////////////////////////
class SpriteRenderer:public Renderer
{
private:
	ID3D11ShaderResourceView* texture_;

	static std::string tag_;

public:
	SpriteRenderer();
	~SpriteRenderer();

	void Initialize(Transform* transform, wchar_t* texturePath);

	void Render(Math::Matrix view, Math::Matrix proj);

	static std::string Tag();
};

