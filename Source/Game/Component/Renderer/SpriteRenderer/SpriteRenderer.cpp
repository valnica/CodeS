/////////////////////////////////////////////////////
// Name : SpriteRenderer
//
// Author : �R�c ����
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#include "SpriteRenderer.h"
#include "../../Transform/Transform.h"
#include "../../../ResourceManager/ResourceManager.h"

__declspec(selectany) std::string SpriteRenderer::tag_("SpriteRenderer");

/////////////////////////////////////////////////////
// Name : SpriteRenderer
//
// Over View : �R�����X�e�[�g
//
// Argument : ����
/////////////////////////////////////////////////////
SpriteRenderer::SpriteRenderer()
{
}

/////////////////////////////////////////////////////
// Name : ~SpriteRenderer
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
SpriteRenderer::~SpriteRenderer()
{
	texture_ = nullptr;
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : ����������
//
// Argument : transform�A�e�N�X�`���̃p�X
//
// Return : ����
/////////////////////////////////////////////////////
void SpriteRenderer::Initialize(Transform * transform, wchar_t * texturePath)
{
	Renderer::Initialize(transform);

	texture_ = ResourceManager::GetInstance()->LoadTexture(texturePath);
}

/////////////////////////////////////////////////////
// Name : Remder
//
// Over View : �`��
//
// Argument : view,projection
//
// Return : ����
/////////////////////////////////////////////////////
void SpriteRenderer::Render(Math::Matrix view, Math::Matrix proj)
{
	Math::Vector3 scale;
	Math::Quaternion rot;
	Math::Vector3 pos;

	transform_->World().Decompose(scale, rot, pos);

	ResourceManager::GetInstance()->SpriteBatch()->Draw(texture_, Math::Vector2(pos.x, pos.y));
}

/////////////////////////////////////////////////////
// Name : Tag
//
// Over View : �^�O�̎擾
//
// Argument : ����
//
// Return : �^�O
/////////////////////////////////////////////////////
std::string SpriteRenderer::Tag()
{
	return tag_;
}
