/////////////////////////////////////////////////////
// Name : Transform
//
// Author : �R�c ����
//
// Date : 2017/8/3
/////////////////////////////////////////////////////
#include "Transform.h"
#include "../../../GameBase/Define/Define.h"

__declspec(selectany) std::string Transform::tag_("Transform");

/////////////////////////////////////////////////////
// Name : Transform
//
// Over View : �R���X�g���N�^
//
// Argument : ����
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
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Transform::~Transform()
{
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
void Transform::Run()
{
	Math::Matrix world = Math::Matrix::Identity;

	//�傫���̕Ԋ�
	auto scale = Math::Matrix::CreateScale(scale_);
	
	//��]�p�̕ϊ�
	auto rotationX = Math::Matrix::CreateRotationX(ToRad(rotation_.x));
	auto rotationY = Math::Matrix::CreateRotationY(ToRad(rotation_.y));
	auto rotationZ = Math::Matrix::CreateRotationZ(ToRad(rotation_.z));
	auto rotation = rotationX * rotationY * rotationZ;

	//���W�̕ϊ�
	auto trans = Math::Matrix::CreateTranslation(position_);

	localWorld_ = scale * rotation * trans;
	world_ = localWorld_;

	//�e�q�\���̌v�Z
	if (parent_)
		world = localWorld_ * parent_->world_;
}

/////////////////////////////////////////////////////
// Name : Position
//
// Over View : ���W�̐ݒ�
//
// Argument : ���W
//
// Return : ����
/////////////////////////////////////////////////////
void Transform::Position(Math::Vector3 position)
{
	position_ = position;
}

/////////////////////////////////////////////////////
// Name : Position
//
// Over View : ���W�̎擾
//
// Argument : ����
//
// Return : ���W
/////////////////////////////////////////////////////
Math::Vector3 Transform::Position()
{
	return position_;
}

/////////////////////////////////////////////////////
// Name : Rotation
//
// Over View : ��]�p�̐ݒ�
//
// Argument : ���W
//
// Return : ����
/////////////////////////////////////////////////////
void Transform::Rotation(Math::Vector3 rotation)
{
	rotation_ = rotation;
}

/////////////////////////////////////////////////////
// Name : Rotation
//
// Over View : ���W�̎擾
//
// Argument : ����
//
// Return : ���W
/////////////////////////////////////////////////////
Math::Vector3 Transform::Rotation()
{
	return rotation_;
}

/////////////////////////////////////////////////////
// Name : Scale
//
// Over View : �傫���̎擾
//
// Argument : �傫��
//
// Return : ����
/////////////////////////////////////////////////////
void Transform::Scale(Math::Vector3 scale)
{
	scale_ = scale;
}

/////////////////////////////////////////////////////
// Name : Scale
//
// Over View : �傫���̎擾
//
// Argument : ����
//
// Return : �傫��
/////////////////////////////////////////////////////
Math::Vector3 Transform::Scale()
{
	return scale_;
}

/////////////////////////////////////////////////////
// Name : World
//
// Over View : ���[���h�}�g���N�X�̎擾
//
// Argument : ����
//
// Return : ���[���h�}�g���N�X
/////////////////////////////////////////////////////
Math::Matrix Transform::World()
{
	return world_;
}

/////////////////////////////////////////////////////
// Name : Tag
//
// Over View : �^�O�̎擾
//
// Argument : ����
//
// Return : ���[���h�}�g���N�X
/////////////////////////////////////////////////////
std::string Transform::Tag()
{
	return tag_;
}
