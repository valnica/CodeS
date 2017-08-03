/////////////////////////////////////////////////////
// Name : Graphics
//
// Author : 山田 聖弥
//
// Day : 2017/8/3
/////////////////////////////////////////////////////
#pragma once

#include <memory>
#include <d3d11.h>
#include <wrl.h>
#include <SimpleMath.h>
#include <SpriteBatch.h>
#include <CommonStates.h>

#include "../Utility/Singleton/Singleton.h"

/////////////////////////////////////////////////////
// Name : Graphics
//
// Over View : グラフィクス関係の管理クラス
/////////////////////////////////////////////////////
class Graphics:public Singleton<Graphics>
{
private:
	
	//デバイス
	Microsoft::WRL::ComPtr<ID3D11Device> device_;

	//コンテキスト
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> context_;

	//スワップチェーン
	Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain_;

	//レンダーターゲット
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTarget_;

	//バックバッファ
	Microsoft::WRL::ComPtr<ID3D11Texture2D> backBuffer_;

	//ステンシルビュー
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> depthStencilView_;

	//デプスステンシル
	Microsoft::WRL::ComPtr<ID3D11Texture2D> depthStencil_;

	//ラスタライズステート
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizeState_;

	//スプライトバッチ
	std::shared_ptr<DirectX::SpriteBatch> spriteBach_;

	//コモンステート
	std::shared_ptr<DirectX::CommonStates> commonState_;

	//コンストラクタ
	Graphics();

	friend Singleton<Graphics>;
public:

	//デストラクタ
	~Graphics();

	//デバイスの作成
	bool CreateDevice(HWND windowHandle_);

	//バッファのクリア
	void ClearBuffer();

	//バッファの入れ替え
	void Present();

	//デバイスの取得
	ID3D11Device* Device();

	//コンテキストの取得
	ID3D11DeviceContext* Context();

	std::shared_ptr<DirectX::SpriteBatch> SpriteBatch()
	{
		return spriteBach_;
	}

	std::shared_ptr<DirectX::CommonStates> CommonState()
	{
		return commonState_;
	}
};

