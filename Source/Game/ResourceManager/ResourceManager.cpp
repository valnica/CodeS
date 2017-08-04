/////////////////////////////////////////////////////
// Name : ResourceManager
//
// Author : �R�c ����
//
// Day : 2017/8/4
/////////////////////////////////////////////////////
#include <WICTextureLoader.h>
#include <Model.h>

#include "ResourceManager.h"
#include "../../GameBase/Graphics/Graphics.h"


/////////////////////////////////////////////////////
// Name : ResourceManager
//
// Over View : �R���X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
ResourceManager::ResourceManager()
{

}


/////////////////////////////////////////////////////
// Name : ~ResourceManager
//
// Over View : �f�X�g���N�^
//
// Argument : ����
/////////////////////////////////////////////////////
ResourceManager::~ResourceManager()
{
	//ResourceView�̉��
	for (auto it = texturePool_.begin(); it != texturePool_.end(); it++)
	{
		it->second->Release();
	}

	texturePool_.clear();
	modelPool_.clear();
}

/////////////////////////////////////////////////////
// Name : Initialize
//
// Over View : ����������
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void ResourceManager::Initialize()
{
	auto device = Graphics::GetInstance()->Device();
	auto context = Graphics::GetInstance()->Context();

	spriteBach_.reset(new DirectX::SpriteBatch(context));
	commonState_.reset(new DirectX::CommonStates(device));
	factory_.reset(new DirectX::DGSLEffectFactory(device));
	factory_->SetDirectory(L"Resources\\CMO");
}

/////////////////////////////////////////////////////
// Name : LoadTexture
//
// Over View : �摜�̓ǂݍ���
//
// Argument : �摜�̃t�@�C���p�X
//
// Return : �摜�̃|�C���^
/////////////////////////////////////////////////////
ID3D11ShaderResourceView * ResourceManager::LoadTexture(wchar_t * texturePath)
{
	//�ǂݍ��񂾂��Ƃ��Ȃ�������ǂݍ���
	if (texturePool_.count(texturePath) <= 0)
	{
		auto device = Graphics::GetInstance()->Device();
		ID3D11ShaderResourceView* shaderResourceView;

		//�摜�̓ǂݍ���
		DirectX::CreateWICTextureFromFile(device, texturePath, nullptr, &shaderResourceView);

		texturePool_[texturePath] = shaderResourceView;
	}

	return texturePool_[texturePath];
}

/////////////////////////////////////////////////////
// Name : LoadModel
//
// Over View : ���f���̓ǂݍ���
//
// Argument : ���f���̃t�@�C���p�X
//
// Return : ���f��
/////////////////////////////////////////////////////
std::shared_ptr<DirectX::Model> ResourceManager::LoadModel(wchar_t * modelPath)
{
	//�ǂݍ��񂾂��Ƃ��Ȃ�������ǂݍ���
	if (modelPool_.count(modelPath) <= 0)
	{
		auto device = Graphics::GetInstance()->Device();

		//���f���ǂݍ���
		modelPool_[modelPath] = std::move(DirectX::Model::CreateFromCMO(device, modelPath, *factory_));
	}

	return modelPool_[modelPath];
}

/////////////////////////////////////////////////////
// Name : SpriteBath
//
// Over View : �X�v���C�g�o�b�`�̎擾
//
// Argument : ����
//
// Return : �X�v���C�g�o�b�`
/////////////////////////////////////////////////////
std::shared_ptr<DirectX::SpriteBatch> ResourceManager::SpriteBatch()
{
	return spriteBach_;
}

/////////////////////////////////////////////////////
// Name : CommonState
//
// Over View : �R�����X�e�[�g
//
// Argument : ����
//
// Return : �R�����X�e�[�g
/////////////////////////////////////////////////////
std::shared_ptr<DirectX::CommonStates> ResourceManager::CommonState()
{
	return commonState_;
}

/////////////////////////////////////////////////////
// Name : Factory
//
// Over View : �t�@�N�g���[�̎擾
//
// Argument : ����
//
// Return : �t�@�N�g���[
/////////////////////////////////////////////////////
std::shared_ptr<DirectX::DGSLEffectFactory> ResourceManager::Factory()
{
	return factory_;
}