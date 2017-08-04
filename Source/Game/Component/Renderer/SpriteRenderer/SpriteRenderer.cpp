/////////////////////////////////////////////////////
// Name : SpriteRenderer
//
// Author : 山田 聖弥
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
// Over View : コモンステート
//
// Argument : 無し
/////////////////////////////////////////////////////
SpriteRenderer::SpriteRenderer()
{
}

/////////////////////////////////////////////////////
// Name : ~SpriteRenderer
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
SpriteRenderer::~SpriteRenderer()
{
	texture_ = nullptr;
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : 初期化処理
//
// Argument : transform、テクスチャのパス
//
// Return : 無し
/////////////////////////////////////////////////////
void SpriteRenderer::Initialize(Transform * transform, wchar_t * texturePath)
{
	Renderer::Initialize(transform);

	texture_ = ResourceManager::GetInstance()->LoadTexture(texturePath);
}

/////////////////////////////////////////////////////
// Name : Remder
//
// Over View : 描画
//
// Argument : view,projection
//
// Return : 無し
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
// Over View : タグの取得
//
// Argument : 無し
//
// Return : タグ
/////////////////////////////////////////////////////
std::string SpriteRenderer::Tag()
{
	return tag_;
}
