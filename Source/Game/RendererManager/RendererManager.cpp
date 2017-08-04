/////////////////////////////////////////////////////
// Name : RenderManager
//
// Author : 山田 聖弥
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
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
RendererManager::RendererManager()
{
	renderer_.clear();
}

/////////////////////////////////////////////////////
// Name : ~RenderManager
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
RendererManager::~RendererManager()
{
	renderer_.clear();
}

/////////////////////////////////////////////////////
// Name : Render
//
// Over View : 描画
//
// Argument : 無し
//
// Return : 無し
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
// Over View : Rendererの登録
//
// Argument : Renderer
//
// Return : 無し
/////////////////////////////////////////////////////
void RendererManager::Entry(Renderer * renderer)
{
	renderer_.push_back(renderer);
}
