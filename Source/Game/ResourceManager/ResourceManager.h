/////////////////////////////////////////////////////
// Name : ResourceManager
//
// Author : �R�c ����
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#pragma once

#include <unordered_map>
#include <d3d11.h>
#include <string>
#include <memory>
#include <Model.h>
#include <SimpleMath.h>
#include <SpriteBatch.h>
#include <CommonStates.h>
#include <Effects.h>

#include "../../GameBase/Utility/Singleton/Singleton.h"

/////////////////////////////////////////////////////
// Name : ResourceManager
//
// Over View : ���\�[�X�̊Ǘ��N���X
/////////////////////////////////////////////////////
class ResourceManager:public Singleton<ResourceManager>
{
private:

	std::unordered_map<std::wstring, ID3D11ShaderResourceView*> texturePool_;
	std::unordered_map<std::wstring,std::shared_ptr<DirectX::Model>> modelPool_;

	//�X�v���C�g�o�b�`
	std::shared_ptr<DirectX::SpriteBatch> spriteBach_;

	//�R�����X�e�[�g
	std::shared_ptr<DirectX::CommonStates> commonState_;

	//�G�t�F�N�g�t�@�N�g���[
	std::shared_ptr<DirectX::DGSLEffectFactory> factory_;

	friend Singleton<ResourceManager>;

	//�R���X�g���N�^
	ResourceManager();

public:

	//�f�X�g���N�^
	~ResourceManager();

	//����������
	void Initialize();

	//�摜�̓ǂݍ���
	ID3D11ShaderResourceView* LoadTexture(wchar_t* texturePath);

	//���f���̓ǂݍ���
	std::shared_ptr<DirectX::Model> LoadModel(wchar_t* modelPath);

	//�X�v���C�g�o�b�`�̎擾
	std::shared_ptr<DirectX::SpriteBatch> SpriteBatch();

	//�R�����X�e�[�g�̎擾
	std::shared_ptr<DirectX::CommonStates> CommonState();

	//�t�@�N�g���[�̎擾
	std::shared_ptr<DirectX::DGSLEffectFactory> Factory();
};

