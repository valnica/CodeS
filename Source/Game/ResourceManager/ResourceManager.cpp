/////////////////////////////////////////////////////
// Name : ResourceManager
//
// Author : 山田 聖弥
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#include <WICTextureLoader.h>
#include <Model.h>

#include "ResourceManager.h"
#include "../../GameBase/Graphics/Graphics.h"


/////////////////////////////////////////////////////
// Name : ResourceManager
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
ResourceManager::ResourceManager()
{

}


/////////////////////////////////////////////////////
// Name : ~ResourceManager
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
ResourceManager::~ResourceManager()
{
	//ResourceViewの解放
	for (auto it = texturePool_.begin(); it != texturePool_.end(); it++)
	{
		it->second->Release();
	}

	texturePool_.clear();
	modelPool_.clear();
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : 初期化処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void ResourceManager::Initialize()
{
	auto device = Graphics::GetInstance()->Device();
	auto context = Graphics::GetInstance()->Context();

	spriteBach_.reset(new DirectX::SpriteBatch(context));
	commonState_.reset(new DirectX::CommonStates(device));
	factory_.reset(new DirectX::DGSLEffectFactory(device));
	factory_->SetDirectory(L"Resources\\CMO");
}

/////////////////////////////////////////////////////
// Name : LoadTexture
//
// Over View : 画像の読み込み
//
// Argument : 画像のファイルパス
//
// Return : 画像のポインタ
/////////////////////////////////////////////////////
ID3D11ShaderResourceView * ResourceManager::LoadTexture(wchar_t * texturePath)
{
	//読み込んだことがなかったら読み込み
	if (texturePool_.count(texturePath) <= 0)
	{
		auto device = Graphics::GetInstance()->Device();
		ID3D11ShaderResourceView* shaderResourceView;

		//画像の読み込み
		DirectX::CreateWICTextureFromFile(device, texturePath, nullptr, &shaderResourceView);

		texturePool_[texturePath] = shaderResourceView;
	}

	return texturePool_[texturePath];
}

/////////////////////////////////////////////////////
// Name : LoadModel
//
// Over View : モデルの読み込み
//
// Argument : モデルのファイルパス
//
// Return : モデル
/////////////////////////////////////////////////////
std::shared_ptr<DirectX::Model> ResourceManager::LoadModel(wchar_t * modelPath)
{
	//読み込んだことがなかったら読み込み
	if (modelPool_.count(modelPath) <= 0)
	{
		auto device = Graphics::GetInstance()->Device();

		//モデル読み込み
		modelPool_[modelPath] = std::move(DirectX::Model::CreateFromCMO(device, modelPath, *factory_));
	}

	return modelPool_[modelPath];
}

/////////////////////////////////////////////////////
// Name : SpriteBath
//
// Over View : スプライトバッチの取得
//
// Argument : 無し
//
// Return : スプライトバッチ
/////////////////////////////////////////////////////
std::shared_ptr<DirectX::SpriteBatch> ResourceManager::SpriteBatch()
{
	return spriteBach_;
}

/////////////////////////////////////////////////////
// Name : CommonState
//
// Over View : コモンステート
//
// Argument : 無し
//
// Return : コモンステート
/////////////////////////////////////////////////////
std::shared_ptr<DirectX::CommonStates> ResourceManager::CommonState()
{
	return commonState_;
}

/////////////////////////////////////////////////////
// Name : Factory
//
// Over View : ファクトリーの取得
//
// Argument : 無し
//
// Return : ファクトリー
/////////////////////////////////////////////////////
std::shared_ptr<DirectX::DGSLEffectFactory> ResourceManager::Factory()
{
	return factory_;
}