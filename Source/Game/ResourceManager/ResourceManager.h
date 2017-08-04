/////////////////////////////////////////////////////
// Name : ResourceManager
//
// Author : 山田 聖弥
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#pragma once

#include <unordered_map>
#include <d3d11.h>
#include <string>
#include <memory>
#include <Model.h>
#include <SimpleMath.h>
#include <SpriteBatch.h>
#include <CommonStates.h>
#include <Effects.h>

#include "../../GameBase/Utility/Singleton/Singleton.h"

/////////////////////////////////////////////////////
// Name : ResourceManager
//
// Over View : リソースの管理クラス
/////////////////////////////////////////////////////
class ResourceManager:public Singleton<ResourceManager>
{
private:

	std::unordered_map<std::wstring, ID3D11ShaderResourceView*> texturePool_;
	std::unordered_map<std::wstring,std::shared_ptr<DirectX::Model>> modelPool_;

	//スプライトバッチ
	std::shared_ptr<DirectX::SpriteBatch> spriteBach_;

	//コモンステート
	std::shared_ptr<DirectX::CommonStates> commonState_;

	//エフェクトファクトリー
	std::shared_ptr<DirectX::DGSLEffectFactory> factory_;

	friend Singleton<ResourceManager>;

	//コンストラクタ
	ResourceManager();

public:

	//デストラクタ
	~ResourceManager();

	//初期化処理
	void Initialize();

	//画像の読み込み
	ID3D11ShaderResourceView* LoadTexture(wchar_t* texturePath);

	//モデルの読み込み
	std::shared_ptr<DirectX::Model> LoadModel(wchar_t* modelPath);

	//スプライトバッチの取得
	std::shared_ptr<DirectX::SpriteBatch> SpriteBatch();

	//コモンステートの取得
	std::shared_ptr<DirectX::CommonStates> CommonState();

	//ファクトリーの取得
	std::shared_ptr<DirectX::DGSLEffectFactory> Factory();
};

