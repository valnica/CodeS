/////////////////////////////////////////////////////
// Name : RenderManager
//
// Author : 山田 聖弥
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#pragma once

#include <list>
#include "../../GameBase/Utility/Singleton/Singleton.h"

class Renderer;

class RendererManager:public Singleton<RendererManager>
{
private:
	//Rendererの登録用クラス
	std::list<Renderer*> renderer_;

	friend Singleton<RendererManager>;

	//コンストラクタ
	RendererManager();

public:

	//デストラクタ
	~RendererManager();

	//描画
	void Render();

	//Rendererの登録
	void Entry(Renderer* renderer);

	//登録のリセット
	void Clear();
};

