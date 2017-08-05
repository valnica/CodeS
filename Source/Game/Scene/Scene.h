/////////////////////////////////////////////////////
// Name : Scene
//
// Author : �R�c ����
//
// Day : 2017/8/5
/////////////////////////////////////////////////////
#pragma once

#include <memory>
#include "../RendererManager/RendererManager.h"

/////////////////////////////////////////////////////
// Name : Scene
//
// Over View : �V�[���̊��N���X
/////////////////////////////////////////////////////
class Scene
{
protected:

public:
	//�R���X�g���N�^
	Scene() = default;

	//�f�X�g���N�^
	virtual ~Scene() = default;

	//�V�[���J��
	virtual std::shared_ptr<Scene> Input() = 0;

	//����������
	virtual void Initialize() = 0;

	//�X�V����
	virtual void Update() = 0;

	//�`�揈��
	virtual void Render()
	{
		RendererManager::GetInstance()->Render();
	}
};

