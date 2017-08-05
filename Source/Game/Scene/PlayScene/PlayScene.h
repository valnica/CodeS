/////////////////////////////////////////////////////
// Name : PlayScene
//
// Author : �R�c ����
//
// Day : 2017/8/5
/////////////////////////////////////////////////////
#pragma once

#include "../Scene.h"

class GameObject;

/////////////////////////////////////////////////////
// Name : PlayScene
//
// Over View : �v���C�V�[��
/////////////////////////////////////////////////////
class PlayScene:public Scene
{
private:
	std::shared_ptr<GameObject> obj_;

public:
	//�R���X�g���N�^
	PlayScene();

	//�f�X�g���N�^
	~PlayScene();

	//�V�[���J��
	std::shared_ptr<Scene> Input() override;

	//����������
	void Initialize() override;
	
	//�X�V����
	void Update() override;
	
	//�`�揈��
	void Render() override;
};

