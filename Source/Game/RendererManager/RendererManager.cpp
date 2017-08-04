/////////////////////////////////////////////////////
// Name : RenderManager
//
// Author : �R�c ����
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#include "RendererManager.h"
#include "../Component/Renderer/Renderer.h"
#include "../Camera/Camera.h"

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
	auto view = Camera::Main()->View();
	auto proj = Camera::Main()->Proj();

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
