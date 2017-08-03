/////////////////////////////////////////////////////
// Name : Graphics
//
// Author : �R�c ����
//
// Day : 2017/8/3
/////////////////////////////////////////////////////
#pragma once

#include <memory>
#include <d3d11.h>
#include <wrl.h>
#include <SimpleMath.h>
#include <SpriteBatch.h>
#include <CommonStates.h>

#include "../Utility/Singleton/Singleton.h"

/////////////////////////////////////////////////////
// Name : Graphics
//
// Over View : �O���t�B�N�X�֌W�̊Ǘ��N���X
/////////////////////////////////////////////////////
class Graphics:public Singleton<Graphics>
{
private:
	
	//�f�o�C�X
	Microsoft::WRL::ComPtr<ID3D11Device> device_;

	//�R���e�L�X�g
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> context_;

	//�X���b�v�`�F�[��
	Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain_;

	//�����_�[�^�[�Q�b�g
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTarget_;

	//�o�b�N�o�b�t�@
	Microsoft::WRL::ComPtr<ID3D11Texture2D> backBuffer_;

	//�X�e���V���r���[
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> depthStencilView_;

	//�f�v�X�X�e���V��
	Microsoft::WRL::ComPtr<ID3D11Texture2D> depthStencil_;

	//���X�^���C�Y�X�e�[�g
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizeState_;

	//�X�v���C�g�o�b�`
	std::shared_ptr<DirectX::SpriteBatch> spriteBach_;

	//�R�����X�e�[�g
	std::shared_ptr<DirectX::CommonStates> commonState_;

	//�R���X�g���N�^
	Graphics();

	friend Singleton<Graphics>;
public:

	//�f�X�g���N�^
	~Graphics();

	//�f�o�C�X�̍쐬
	bool CreateDevice(HWND windowHandle_);

	//�o�b�t�@�̃N���A
	void ClearBuffer();

	//�o�b�t�@�̓���ւ�
	void Present();

	//�f�o�C�X�̎擾
	ID3D11Device* Device();

	//�R���e�L�X�g�̎擾
	ID3D11DeviceContext* Context();

	std::shared_ptr<DirectX::SpriteBatch> SpriteBatch()
	{
		return spriteBach_;
	}

	std::shared_ptr<DirectX::CommonStates> CommonState()
	{
		return commonState_;
	}
};

