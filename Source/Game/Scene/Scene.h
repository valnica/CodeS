/////////////////////////////////////////////////////
// Name : Scene
//
// Author : 山田 聖弥
//
// Day : 2017/8/5
/////////////////////////////////////////////////////
#pragma once

#include <memory>
#include "../RendererManager/RendererManager.h"

/////////////////////////////////////////////////////
// Name : Scene
//
// Over View : シーンの基底クラス
/////////////////////////////////////////////////////
class Scene
{
protected:

public:
	//コンストラクタ
	Scene() = default;

	//デストラクタ
	virtual ~Scene() = default;

	//シーン遷移
	virtual std::shared_ptr<Scene> Input() = 0;

	//初期化処理
	virtual void Initialize() = 0;

	//更新処理
	virtual void Update() = 0;

	//描画処理
	virtual void Render()
	{
		RendererManager::GetInstance()->Render();
	}
};

