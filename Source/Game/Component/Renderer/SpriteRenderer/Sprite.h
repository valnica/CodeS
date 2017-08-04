/////////////////////////////////////////////////////
// Name : Sprite
//
// Author : �R�c ����
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
// Over View : �摜�N���X
/////////////////////////////////////////////////////
class Sprite
{
private:
	//�摜
	ID3D11ShaderResourceView* texture_;

	//���W
	Math::Vector2 pos_;

	//�摜�̐؂��蕝
	RECT rect_;

	//��]�p
	float rot_;

	//�g�嗦
	float scale_;

	//�A���J�[
	Math::Vector2 origine_;

	//�F
	Math::Color color_;

public:
	//�R���X�g���N�^
	Sprite(wchar_t* texturePass,RECT rect);

	//�f�X�g���N�^
	~Sprite();

	//����������
	void Initialize(Math::Vector2 pos = Math::Vector2::Zero);

	//�`�揈��
	void Render();

	//���W�̐ݒ�Ǝ擾
	void Pos(Math::Vector2 pos);
	Math::Vector2 Pos();

	//�؂���͈͂̐ݒ�Ǝ擾
	void Rect(RECT rect);
	RECT Rect();

	//��]�p�̐ݒ�Ǝ擾
	void Rotation(float rot);
	float Rotation();

	//�g�嗦�̐ݒ�Ǝ擾
	void Scale(float scale);
	float Scale();

	//�A���J�[�̐ݒ�Ǝ擾
	void Origine(Math::Vector2 origine);
	Math::Vector2 Origine();

	//�F�̐ݒ�Ǝ擾
	void Color(Math::Color color);
	Math::Color Color();

	//�����蔻��p�̃{�b�N�X�̎擾
	Collider::BoundingBox BoundingBox();

	//�����蔻��p�̉~�̎擾
	Collider::Circle Circle();
};

