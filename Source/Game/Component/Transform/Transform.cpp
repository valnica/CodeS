/////////////////////////////////////////////////////
// Name : Transform
//
// Author : 山田 聖弥
//
// Date : 2017/8/3
/////////////////////////////////////////////////////
#include "Transform.h"
#include "../../../GameBase/Define/Define.h"

__declspec(selectany) std::string Transform::tag_("Transform");

/////////////////////////////////////////////////////
// Name : Transform
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Transform::Transform()
	:Component(), position_(Math::Vector3::Zero)
	,rotation_(Math::Vector3::Zero),scale_(Math::Vector3(1.0f,1.0f,1.0f))
	,parent_(nullptr)
{
}

/////////////////////////////////////////////////////
// Name : ~Transform
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Transform::~Transform()
{
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : 更新処理
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void Transform::Run()
{
	Math::Matrix world = Math::Matrix::Identity;

	//大きさの返還
	auto scale = Math::Matrix::CreateScale(scale_);
	
	//回転角の変換
	auto rotationX = Math::Matrix::CreateRotationX(ToRad(rotation_.x));
	auto rotationY = Math::Matrix::CreateRotationY(ToRad(rotation_.y));
	auto rotationZ = Math::Matrix::CreateRotationZ(ToRad(rotation_.z));
	auto rotation = rotationX * rotationY * rotationZ;

	//座標の変換
	auto trans = Math::Matrix::CreateTranslation(position_);

	localWorld_ = scale * rotation * trans;
	world_ = localWorld_;

	//親子構造の計算
	if (parent_)
		world = localWorld_ * parent_->world_;
}

/////////////////////////////////////////////////////
// Name : Position
//
// Over View : 座標の設定
//
// Argument : 座標
//
// Return : 無し
/////////////////////////////////////////////////////
void Transform::Position(Math::Vector3 position)
{
	position_ = position;
}

/////////////////////////////////////////////////////
// Name : Position
//
// Over View : 座標の取得
//
// Argument : 無し
//
// Return : 座標
/////////////////////////////////////////////////////
Math::Vector3 Transform::Position()
{
	return position_;
}

/////////////////////////////////////////////////////
// Name : Rotation
//
// Over View : 回転角の設定
//
// Argument : 座標
//
// Return : 無し
/////////////////////////////////////////////////////
void Transform::Rotation(Math::Vector3 rotation)
{
	rotation_ = rotation;
}

/////////////////////////////////////////////////////
// Name : Rotation
//
// Over View : 座標の取得
//
// Argument : 無し
//
// Return : 座標
/////////////////////////////////////////////////////
Math::Vector3 Transform::Rotation()
{
	return rotation_;
}

/////////////////////////////////////////////////////
// Name : Scale
//
// Over View : 大きさの取得
//
// Argument : 大きさ
//
// Return : 無し
/////////////////////////////////////////////////////
void Transform::Scale(Math::Vector3 scale)
{
	scale_ = scale;
}

/////////////////////////////////////////////////////
// Name : Scale
//
// Over View : 大きさの取得
//
// Argument : 無し
//
// Return : 大きさ
/////////////////////////////////////////////////////
Math::Vector3 Transform::Scale()
{
	return scale_;
}

/////////////////////////////////////////////////////
// Name : World
//
// Over View : ワールドマトリクスの取得
//
// Argument : 無し
//
// Return : ワールドマトリクス
/////////////////////////////////////////////////////
Math::Matrix Transform::World()
{
	return world_;
}

/////////////////////////////////////////////////////
// Name : Tag
//
// Over View : タグの取得
//
// Argument : 無し
//
// Return : ワールドマトリクス
/////////////////////////////////////////////////////
std::string Transform::Tag()
{
	return tag_;
}
