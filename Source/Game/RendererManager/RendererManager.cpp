/////////////////////////////////////////////////////
// Name : RenderManager
//
// Author : �R�c ����
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#include "RendererManager.h"
#include "../Component/Renderer/Renderer.h"

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

/////////////////////////////////////////////////////
// Name : RenderManager
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
RendererManager::RendererManager()
{
	renderer_.clear();
}

/////////////////////////////////////////////////////
// Name : ~RenderManager
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
RendererManager::~RendererManager()
{
	renderer_.clear();
}

/////////////////////////////////////////////////////
// Name : Render
//
// Over View : �`��
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void RendererManager::Render()
{
	auto view = Math::Matrix::CreateLookAt(Math::Vector3(0, 3, 5), Math::Vector3(0, 0, 0), Math::Vector3(0, 1, 0));
	auto proj = Math::Matrix::CreatePerspectiveFieldOfView(45, 1280.0f / 720.0f, 0.1, 1000);

	for each(auto renderer in renderer_)
	{
		renderer->Render(view, proj);
	}

	renderer_.clear();
}

/////////////////////////////////////////////////////
// Name : Entry
//
// Over View : Renderer�̓o�^
//
// Argument : Renderer
//
// Return : ����
/////////////////////////////////////////////////////
void RendererManager::Entry(Renderer * renderer)
{
	renderer_.push_back(renderer);
}
