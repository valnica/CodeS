/////////////////////////////////////////////////////
// Name : Sprite
//
// Author : �R�c ����
//
// Day : 2017/7/7
/////////////////////////////////////////////////////
#include "Sprite.h"
#include "SpriteManager/SpriteManager.h"

using namespace DirectX;
using namespace Math;

/////////////////////////////////////////////////////
// Name : Sprite
//
// Over View : �R���X�g���N�^
//
// Argument : �摜�̃p�X
/////////////////////////////////////////////////////
Sprite::Sprite(wchar_t* texturePass,RECT rect)
	:texture_(nullptr),pos_(Vector2::Zero),rect_(rect)
	,rot_(0.0f),scale_(1.0f),origine_(Vector2::Zero)
	,color_(Colors::White)
{
	texture_ = SpriteManager::GetInstance()->LoadTexture(texturePass);
}

/////////////////////////////////////////////////////
// Name : ~Sprite
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
Sprite::~Sprite()
{
	texture_ = nullptr;
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : ����������
//
// Argument : ���W
//
// Return : ����
/////////////////////////////////////////////////////
void Sprite::Initialize(Vector2 pos)
{
	pos_ = pos;
}

/////////////////////////////////////////////////////
// Name : Render
//
// Over View : �`�揈��
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void Sprite::Render()
{
	auto spriteBatch = SpriteManager::GetInstance()->SpriteBatch();

	spriteBatch->Draw(texture_, pos_, &rect_, color_, rot_, origine_,scale_);

	Circle();
}

/////////////////////////////////////////////////////
// Name : Pos
//
// Over View : ���W�̃Z�b�^�[
//
// Argument : ���W
//
// Return : ����
/////////////////////////////////////////////////////
void Sprite::Pos(Math::Vector2 pos)
{
	pos_ = pos;
}

/////////////////////////////////////////////////////
// Name : Pos
//
// Over View : ���W�̃Q�b�^�[
//
// Argument : ����
//
// Return : ���W
/////////////////////////////////////////////////////
Vector2 Sprite::Pos()
{
	return pos_;
}

/////////////////////////////////////////////////////
// Name : Rect
//
// Over View : �摜�̐؂���͈͂̃Z�b�^�[
//
// Argument : �摜�̐؂���͈�
//
// Return : ����
/////////////////////////////////////////////////////
void Sprite::Rect(RECT rect)
{
	rect_ = rect;
}

/////////////////////////////////////////////////////
// Name : Rect
//
// Over View : �摜�̐؂���͈͂̃Q�b�^�[
//
// Argument : ����
//
// Return : �摜�̐؂���͈�
/////////////////////////////////////////////////////
RECT Sprite::Rect()
{
	return rect_;
}

/////////////////////////////////////////////////////
// Name : Rotation
//
// Over View : ��]�p�̃Z�b�^�[
//
// Argument : ��]�p
//
// Return : ����
/////////////////////////////////////////////////////
void Sprite::Rotation(float rot)
{
	rot_ = rot;
}

/////////////////////////////////////////////////////
// Name : Rotation
//
// Over View : ��]�p�̃Q�b�^�[
//
// Argument : ����
//
// Return : ��]�p
/////////////////////////////////////////////////////
float Sprite::Rotation()
{
	return rot_;
}

/////////////////////////////////////////////////////
// Name : Scale
//
// Over View : �g�嗦�̃Z�b�^�[�ƃQ�b�^�[
//
// Argument : �g�嗦
//
// Return : ����
/////////////////////////////////////////////////////
void Sprite::Scale(float scale)
{
	scale_ = scale;
}

/////////////////////////////////////////////////////
// Name : Scale
//
// Over View : �g�嗦�̃Q�b�^�[
//
// Argument : ����
//
// Return : �g�嗦
/////////////////////////////////////////////////////
float Sprite::Scale()
{
	return scale_;
}

/////////////////////////////////////////////////////
// Name : Origine
//
// Over View : �A���J�[�̃Q�b�^�[
//
// Argument : �A���J�[�|�C���g
//
// Return : ����
/////////////////////////////////////////////////////
void Sprite::Origine(Math::Vector2 origine)
{
	origine_ = origine;
}

/////////////////////////////////////////////////////
// Name : Origine
//
// Over View : �A���J�[�̃Q�b�^�[
//
// Argument : ����
//
// Return : �A���J�[�|�C���g
/////////////////////////////////////////////////////
Math::Vector2 Sprite::Origine()
{
	return origine_;
}

/////////////////////////////////////////////////////
// Name : Color
//
// Over View : �F�̃Z�b�^�[
//
// Argument : �F
//
// Return : ����
/////////////////////////////////////////////////////
void Sprite::Color(Math::Color color)
{
	color_ = color;
}

/////////////////////////////////////////////////////
// Name : Color
//
// Over View : �F�̃Q�b�^�[
//
// Argument : ����
//
// Return : �F
/////////////////////////////////////////////////////
Math::Color Sprite::Color()
{
	return color_;
}

/////////////////////////////////////////////////////
// Name : BoundingBox
//
// Over View : �����蔻��p�̃{�b�N�X�̎擾
//
// Argument : ����
//
// Return : �����蔻��p�̃{�b�N�X
/////////////////////////////////////////////////////
Collider::BoundingBox Sprite::BoundingBox()
{
	//���S�_����e���_�̌v�Z
	auto top = pos_.y - origine_.y;
	auto bottom = pos_.y + ((rect_.bottom - rect_.top) - origine_.y);
	auto left = pos_.x - origine_.x;
	auto right = pos_.x + ((rect_.right - rect_.left) - origine_.x);

	top *= scale_;
	bottom *= scale_;
	left *= scale_;
	right *= scale_;

	return Collider::BoundingBox(top, bottom, left, right);
}

/////////////////////////////////////////////////////
// Name : Circle
//
// Over View : �����蔻��p�̉~�̎擾
//
// Argument : ����
//
// Return : �����蔻��p�̉~
/////////////////////////////////////////////////////
Collider::Circle Sprite::Circle()
{
	//���S�_����摜�̒��S�̌v�Z
	Vector2 center;
	center.x = pos_.x + (rect_.right - rect_.left) / 2 - origine_.x;
	center.y = pos_.y + (rect_.bottom - rect_.top) / 2 - origine_.y;

	//���a
	auto radius = (rect_.right - rect_.left) / 2;

	center *= scale_;
	radius *= scale_;

	return Collider::Circle(center, radius);
}
