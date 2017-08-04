/////////////////////////////////////////////////////
// Name : Camera
//
// Author : 山田 聖弥
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#include "Camera.h"
#include "../Component/Transform/Transform.h"
#include "../../GameBase/Define/Define.h"

std::shared_ptr<Camera> Camera::mainCamera_ = nullptr;

/////////////////////////////////////////////////////
// Name : Camera
//
// Over View : コンストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Camera::Camera()
	:GameObject(), target_(nullptr), up_(Math::Vector3(0.0f, 1.0f, 0.0f))
	, fov_(45), aspect_(1280.0f / 720.0f), near_(0.1f), far_(1000)
{
}

/////////////////////////////////////////////////////
// Name : ~Camera
//
// Over View : デストラクタ
//
// Argument : 無し
/////////////////////////////////////////////////////
Camera::~Camera()
{
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : 初期化処理
//
// Argument : 視点、カメラの上方向、視野角、ウィンドウの幅、高さ、最近値、最遠値、ターゲット
//
// Return : 無し
/////////////////////////////////////////////////////
void Camera::Initialize(Math::Vector3 eye, Math::Vector3 up, int fov, int width, int height, float nearClip, float farClip, Transform * target)
{
	transform_->Position(eye);
	target_ = target;
	up_ = up;
	fov_ = fov;
	aspect_ = (float)width / (float)height;
	near_ = nearClip;
	far_ = farClip;
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
void Camera::Update()
{
	Math::Vector3 ref;
	if (target_)
	{
		ref = target_->Position();
	}
	else
	{
		auto rotationX = Math::Matrix::CreateRotationX(ToRad(transform_->Rotation().x));
		auto rotationY = Math::Matrix::CreateRotationY(ToRad(transform_->Rotation().y));
		auto rotationZ = Math::Matrix::CreateRotationZ(ToRad(transform_->Rotation().z));
		auto rotation = rotationX * rotationY * rotationZ;

		ref = Math::Vector3::TransformNormal(transform_->Position() + Math::Vector3(0.0f, 0.0f, -5.0f), rotation);
	}

	view_ = Math::Matrix::CreateLookAt(transform_->Position(), ref, up_);
	proj_ = Math::Matrix::CreatePerspectiveFieldOfView(fov_, aspect_, near_, far_);
}

/////////////////////////////////////////////////////
// Name : Target
//
// Over View : ターゲットの設定
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
void Camera::Target(Transform * target)
{
	target_ = target;
}

/////////////////////////////////////////////////////
// Name : View
//
// Over View : ビュー行列の取得
//
// Argument : 無し
//
// Return : ビュー行列
/////////////////////////////////////////////////////
Math::Matrix Camera::View()
{
	return view_;
}

/////////////////////////////////////////////////////
// Name : proj
//
// Over View : プロジェクション行列の取得
//
// Argument : 無し
//
// Return : プロジェクション行列
/////////////////////////////////////////////////////
Math::Matrix Camera::Proj()
{
	return proj_;
}

/////////////////////////////////////////////////////
// Name : Main
//
// Over View : メインカメラの取得
//
// Argument : 無し
//
// Return : 無し
/////////////////////////////////////////////////////
std::shared_ptr<Camera> Camera::Main()
{
	return mainCamera_;
}

/////////////////////////////////////////////////////
// Name : Main
//
// Over View : メインカメラの設定
//
// Argument : カメラ
//
// Return : 無し
/////////////////////////////////////////////////////
void Camera::Main(std::shared_ptr<Camera> camera)
{
	mainCamera_ = camera;
}
