/////////////////////////////////////////////////////
// Name : Camera
//
// Author : �R�c ����
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
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Camera::Camera()
	:GameObject(), target_(nullptr), up_(Math::Vector3(0.0f, 1.0f, 0.0f))
	, fov_(45), aspect_(1280.0f / 720.0f), near_(0.1f), far_(1000)
{
}

/////////////////////////////////////////////////////
// Name : ~Camera
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Camera::~Camera()
{
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : ����������
//
// Argument : ���_�A�J�����̏�����A����p�A�E�B���h�E�̕��A�����A�ŋߒl�A�ŉ��l�A�^�[�Q�b�g
//
// Return : ����
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
// Over View : �X�V����
//
// Argument : ����
//
// Return : ����
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
// Over View : �^�[�Q�b�g�̐ݒ�
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void Camera::Target(Transform * target)
{
	target_ = target;
}

/////////////////////////////////////////////////////
// Name : View
//
// Over View : �r���[�s��̎擾
//
// Argument : ����
//
// Return : �r���[�s��
/////////////////////////////////////////////////////
Math::Matrix Camera::View()
{
	return view_;
}

/////////////////////////////////////////////////////
// Name : proj
//
// Over View : �v���W�F�N�V�����s��̎擾
//
// Argument : ����
//
// Return : �v���W�F�N�V�����s��
/////////////////////////////////////////////////////
Math::Matrix Camera::Proj()
{
	return proj_;
}

/////////////////////////////////////////////////////
// Name : Main
//
// Over View : ���C���J�����̎擾
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
std::shared_ptr<Camera> Camera::Main()
{
	return mainCamera_;
}

/////////////////////////////////////////////////////
// Name : Main
//
// Over View : ���C���J�����̐ݒ�
//
// Argument : �J����
//
// Return : ����
/////////////////////////////////////////////////////
void Camera::Main(std::shared_ptr<Camera> camera)
{
	mainCamera_ = camera;
}
