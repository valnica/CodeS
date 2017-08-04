/////////////////////////////////////////////////////
// Name : TransForm
//
// Author : 山田 聖弥
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#pragma once

#include <d3d11.h>
#include <SimpleMath.h>
#include <string>

#include "../Component.h"

namespace Math = DirectX::SimpleMath;

/////////////////////////////////////////////////////
// Name : Game
//
// Over View : ゲームクラス
/////////////////////////////////////////////////////
class Transform:public Component
{
private:
	//座標
	Math::Vector3 position_;
	
	//回転角
	Math::Vector3 rotation_;
	
	//大きさ
	Math::Vector3 scale_;

	//ワールド
	Math::Matrix world_;

	//ローカルワールド
	Math::Matrix localWorld_;

	//親の設定
	Transform* parent_;

	//コンポネントの名前
	static std::string tag_;

public:
	Transform();
	~Transform();

	//初期化処理
	void Initialize(Math::Vector3 position, Math::Vector3 rotation, Math::Vector3 scale);

	//更新処理
	void Run() override;
	
	//座標
	void Position(Math::Vector3 pos);
	Math::Vector3 Position();

	//回転角
	void Rotation(Math::Vector3 rotation);
	Math::Vector3 Rotation();

	//大きさ
	void Scale(Math::Vector3 scale);
	Math::Vector3 Scale();

	//ワールド座標の取得
	Math::Matrix World();

	//タグの取得
	static std::string Tag();

	//親
	Transform* Parent();
	void Parent(Transform* parent);
};