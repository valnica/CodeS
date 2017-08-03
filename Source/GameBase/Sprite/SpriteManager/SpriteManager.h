/////////////////////////////////////////////////////
// Name : SpriteManager
//
// Author : �R�c ����
//
// Day : 2017/7/7
/////////////////////////////////////////////////////
#pragma once

#include <d3d11.h>
#include <map>
#include <memory>
#include <SpriteBatch.h>
#include <CommonStates.h>

#include "../../Utility/Singleton/Singleton.h"

/////////////////////////////////////////////////////
// Name : SpriteManager
//
// Over View : �Q�[���̃��C���N���X
/////////////////////////////////////////////////////
class SpriteManager:public Singleton<SpriteManager>
{
private:
	std::map<std::wstring,ID3D11ShaderResourceView*> shaderResourceViewPool_;
	std::shared_ptr<DirectX::SpriteBatch> spriteBatch_;
	std::shared_ptr<DirectX::CommonStates> commonState_;

	friend Singleton<SpriteManager>;

	//�R���X�g���N�^
	SpriteManager();
public:

	//�f�X�g���N�^
	~SpriteManager();

	//����������
	void Initialize();

	//�摜�̓ǂݍ���
	ID3D11ShaderResourceView* LoadTexture(wchar_t* pass);

	//SpriteBatch�̎擾
	std::shared_ptr<DirectX::SpriteBatch> SpriteBatch();

	//CommonState�̎擾
	std::shared_ptr<DirectX::CommonStates> CommonState();
};