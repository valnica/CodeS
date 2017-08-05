/////////////////////////////////////////////////////
// Name : Camera
//
// Author : 山田 聖弥
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#pragma once

#include <d3d11.h>
#include <SimpleMath.h>
#include "../GameObject.h"

namespace Math = DirectX::SimpleMath;

class Transform;

/////////////////////////////////////////////////////
// Name : Camera
//
// Over View : カメラ
/////////////////////////////////////////////////////
class Camera:public GameObject
{
private:

	//ターゲットのtransform
	Transform* target_;

	//ビュー行列
	Math::Matrix view_;

	//プロジェクション行列
	Math::Matrix proj_;

	//カメラの上方向
	Math::Vector3 up_;

	//視野角
	int fov_;

	//アスペクト比
	float aspect_;

	//ニアークリップ
	float near_;

	//ファークリップ
	float far_;

	//メインカメラ
	static std::shared_ptr<Camera> mainCamera_;

public:
	Camera();
	~Camera();

	//初期化処理
	void Initialize(Math::Vector3 eye, Math::Vector3 up, int fov, int width, int height, float nearClip, float farClip, Transform* target = nullptr);
	
	//更新処理
	void Update();

	//ターゲット
	void Target(Transform* target);

	//ビュー行列の取得
	Math::Matrix View();

	//プロジェクション行列の取得
	Math::Matrix Proj();

	//メインカメラ
	static std::shared_ptr<Camera> Main();
	static void Main(std::shared_ptr<Camera> camera);
};

