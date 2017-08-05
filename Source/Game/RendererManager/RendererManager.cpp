/////////////////////////////////////////////////////
// Name : RenderManager
//
// Author : �R�c ����
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#include "RendererManager.h"
#include "../Component/Renderer/Renderer.h"
#include "../GameObject/Camera/Camera.h"

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
	Clear();
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
	Clear();
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

	Clear();
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

/////////////////////////////////////////////////////
// Name : Clear
//
// Over View : �o�^�̃��Z�b�g
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void RendererManager::Clear()
{
	renderer_.clear();
}
