/////////////////////////////////////////////////////
// Name : PlayScene
//
// Author : 山田 聖弥
//
// Day : 2017/8/5
/////////////////////////////////////////////////////
#pragma once

#include "../Scene.h"

class GameObject;

/////////////////////////////////////////////////////
// Name : PlayScene
//
// Over View : プレイシーン
/////////////////////////////////////////////////////
class PlayScene:public Scene
{
private:
	std::shared_ptr<GameObject> obj_;

public:
	//コンストラクタ
	PlayScene();

	//デストラクタ
	~PlayScene();

	//シーン遷移
	std::shared_ptr<Scene> Input() override;

	//初期化処理
	void Initialize() override;
	
	//更新処理
	void Update() override;
	
	//描画処理
	void Render() override;
};

