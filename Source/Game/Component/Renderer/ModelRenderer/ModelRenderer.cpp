/////////////////////////////////////////////////////
// Name : ModelRenderer
//
// Author : �R�c ����
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
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
ModelRenderer::ModelRenderer()
	:model_(nullptr)
{
}

/////////////////////////////////////////////////////
// Name : ~ModelRenderer
//
// Over View : ����
//
// Argument : ����
/////////////////////////////////////////////////////
ModelRenderer::~ModelRenderer()
{
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : ����������
//
// Argument : transform,���f���̃t�@�C���p�X
//
// Return : ����
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
// Over View : �`�揈��
//
// Argument : view,projection
//
// Return : ����
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
// Over View : Component�̃^�O�̎擾
//
// Argument : ����
//
// Return : �^�O
/////////////////////////////////////////////////////
std::string ModelRenderer::Tag()
{
	return tag_;
}