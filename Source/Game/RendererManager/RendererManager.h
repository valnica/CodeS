/////////////////////////////////////////////////////
// Name : RenderManager
//
// Author : �R�c ����
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#pragma once

#include <list>
#include "../../GameBase/Utility/Singleton/Singleton.h"

class Renderer;

class RendererManager:public Singleton<RendererManager>
{
private:
	//Renderer�̓o�^�p�N���X
	std::list<Renderer*> renderer_;

	friend Singleton<RendererManager>;

	//�R���X�g���N�^
	RendererManager();

public:

	//�f�X�g���N�^
	~RendererManager();

	//�`��
	void Render();

	//Renderer�̓o�^
	void Entry(Renderer* renderer);

	//�o�^�̃��Z�b�g
	void Clear();
};

