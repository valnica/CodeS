/////////////////////////////////////////////////////
// Name : Sprite
//
// Author : 山田 聖弥
//
// Day : 2017/7/7
/////////////////////////////////////////////////////
#pragma once

#include <d3d11.h>
#include <SimpleMath.h>
#include <memory>
#include "../Collision/Collision.h"

namespace Math = DirectX::SimpleMath;

/////////////////////////////////////////////////////
// Name : Sprite
//
// Over View : 画像クラス
/////////////////////////////////////////////////////
class Sprite
{
private:
	//画像
	ID3D11ShaderResourceView* texture_;

	//座標
	Math::Vector2 pos_;

	//画像の切り取り幅
	RECT rect_;

	//回転角
	float rot_;

	//拡大率
	float scale_;

	//アンカー
	Math::Vector2 origine_;

	//色
	Math::Color color_;

public:
	//コンストラクタ
	Sprite(wchar_t* texturePass,RECT rect);

	//デストラクタ
	~Sprite();

	//初期化処理
	void Initialize(Math::Vector2 pos = Math::Vector2::Zero);

	//描画処理
	void Render();

	//座標の設定と取得
	void Pos(Math::Vector2 pos);
	Math::Vector2 Pos();

	//切り取り範囲の設定と取得
	void Rect(RECT rect);
	RECT Rect();

	//回転角の設定と取得
	void Rotation(float rot);
	float Rotation();

	//拡大率の設定と取得
	void Scale(float scale);
	float Scale();

	//アンカーの設定と取得
	void Origine(Math::Vector2 origine);
	Math::Vector2 Origine();

	//色の設定と取得
	void Color(Math::Color color);
	Math::Color Color();

	//当たり判定用のボックスの取得
	Collider::BoundingBox BoundingBox();

	//当たり判定用の円の取得
	Collider::Circle Circle();
};

