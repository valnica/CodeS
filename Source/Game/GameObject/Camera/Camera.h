/////////////////////////////////////////////////////
// Name : Camera
//
// Author : �R�c ����
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
// Over View : �J����
/////////////////////////////////////////////////////
class Camera:public GameObject
{
private:

	//�^�[�Q�b�g��transform
	Transform* target_;

	//�r���[�s��
	Math::Matrix view_;

	//�v���W�F�N�V�����s��
	Math::Matrix proj_;

	//�J�����̏����
	Math::Vector3 up_;

	//����p
	int fov_;

	//�A�X�y�N�g��
	float aspect_;

	//�j�A�[�N���b�v
	float near_;

	//�t�@�[�N���b�v
	float far_;

	//���C���J����
	static std::shared_ptr<Camera> mainCamera_;

public:
	Camera();
	~Camera();

	//����������
	void Initialize(Math::Vector3 eye, Math::Vector3 up, int fov, int width, int height, float nearClip, float farClip, Transform* target = nullptr);
	
	//�X�V����
	void Update();

	//�^�[�Q�b�g
	void Target(Transform* target);

	//�r���[�s��̎擾
	Math::Matrix View();

	//�v���W�F�N�V�����s��̎擾
	Math::Matrix Proj();

	//���C���J����
	static std::shared_ptr<Camera> Main();
	static void Main(std::shared_ptr<Camera> camera);
};

