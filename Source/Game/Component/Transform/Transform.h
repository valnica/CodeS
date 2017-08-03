/////////////////////////////////////////////////////
// Name : TransForm
//
// Author : �R�c ����
//
// Day : 2017/8/3
/////////////////////////////////////////////////////
#pragma once

#include <d3d11.h>
#include <SimpleMath.h>

#include "../Component.h"

namespace Math = DirectX::SimpleMath;

/////////////////////////////////////////////////////
// Name : Game
//
// Over View : �Q�[���N���X
/////////////////////////////////////////////////////
class Transform:public Component
{
private:
	//���W
	Math::Vector3 position_;
	
	//��]�p
	Math::Vector3 rotation_;
	
	//�傫��
	Math::Vector3 scale_;

	//���[���h
	Math::Matrix world_;

	//���[�J�����[���h
	Math::Matrix localWorld_;

	//�e�̐ݒ�
	Transform* parent_;

public:
	Transform();
	~Transform();

	//�X�V����
	void Run() override;
	
	//���W
	void Position(Math::Vector3 pos);
	Math::Vector3 Position();

	//��]�p
	void Rotation(Math::Vector3 rotation);
	Math::Vector3 Rotation();

	//�傫��
	void Scale(Math::Vector3 scale);
	Math::Vector3 Scale();
};