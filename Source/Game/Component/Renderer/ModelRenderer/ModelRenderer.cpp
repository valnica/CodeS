/////////////////////////////////////////////////////
// Name : ModelRenderer
//
// Author : 山田 聖弥
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#include "ModelRenderer.h"
#include "../../Transform/Transform.h"
#include "../../../../GameBase/Graphics/Graphics.h"
#include "../../../ResourceManager/ResourceManager.h"

__declspec(selectany) std::string ModelRenderer::tag_("ModelRenderer");

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

/////////////////////////////////////////////////////
// Name : ModelRenderer
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
ModelRenderer::ModelRenderer()
	:model_(nullptr)
{
}

/////////////////////////////////////////////////////
// Name : ~ModelRenderer
//
// Over View : 無し
//
// Argument : 無し
/////////////////////////////////////////////////////
ModelRenderer::~ModelRenderer()
{
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : 初期化処理
//
// Argument : transform,モデルのファイルパス
//
// Return : 無し
/////////////////////////////////////////////////////
void ModelRenderer::Initialize(Transform* transform, wchar_t * modelPath)
{
	Renderer::Initialize(transform);

	auto device = Graphics::GetInstance()->Device();
	model_ = ResourceManager::GetInstance()->LoadModel(modelPath);
}

/////////////////////////////////////////////////////
// Name : Render
//
// Over View : 描画処理
//
// Argument : view,projection
//
// Return : 無し
/////////////////////////////////////////////////////
void ModelRenderer::Render(Math::Matrix view, Math::Matrix proj)
{
	auto context = Graphics::GetInstance()->Context();
	auto commonState = ResourceManager::GetInstance()->CommonState();

	model_->Draw(context, *commonState, transform_->World(), view, proj);
}

/////////////////////////////////////////////////////
// Name : Tag
//
// Over View : Componentのタグの取得
//
// Argument : 無し
//
// Return : タグ
/////////////////////////////////////////////////////
std::string ModelRenderer::Tag()
{
	return tag_;
}