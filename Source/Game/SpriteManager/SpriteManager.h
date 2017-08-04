/////////////////////////////////////////////////////
// Name : SpriteManager
//
// Author : 山田 聖弥
//
// Day : 2017/7/7
/////////////////////////////////////////////////////
#pragma once

#include <d3d11.h>
#include <map>
#include <memory>
#include <SpriteBatch.h>
#include <CommonStates.h>

#include "../../Utility/Singleton/Singleton.h"

/////////////////////////////////////////////////////
// Name : SpriteManager
//
// Over View : ゲームのメインクラス
/////////////////////////////////////////////////////
class SpriteManager:public Singleton<SpriteManager>
{
private:
	std::map<std::wstring,ID3D11ShaderResourceView*> shaderResourceViewPool_;
	std::shared_ptr<DirectX::SpriteBatch> spriteBatch_;
	std::shared_ptr<DirectX::CommonStates> commonState_;

	friend Singleton<SpriteManager>;

	//コンストラクタ
	SpriteManager();
public:

	//デストラクタ
	~SpriteManager();

	//初期化処理
	void Initialize();

	//画像の読み込み
	ID3D11ShaderResourceView* LoadTexture(wchar_t* pass);

	//SpriteBatchの取得
	std::shared_ptr<DirectX::SpriteBatch> SpriteBatch();

	//CommonStateの取得
	std::shared_ptr<DirectX::CommonStates> CommonState();
};