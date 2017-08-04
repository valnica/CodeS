/////////////////////////////////////////////////////
// Name : Graphics
//
// Author : �R�c ����
//
// Day : 2017/8/3
/////////////////////////////////////////////////////
#include "Graphics.h"

#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : �X�V����
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
Graphics::Graphics()
{
}

/////////////////////////////////////////////////////
// Name : Update
//
// Over View : �X�V����
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
Graphics::~Graphics()
{
}

/////////////////////////////////////////////////////
// Name : CreateDevice
//
// Over View : �����_�����O�֌W�̂��̍쐬
//
// Argument : �E�B���h�E�n���h��
//
// Return : �쐬���o�����Ƃ���true
/////////////////////////////////////////////////////
bool Graphics::CreateDevice(HWND windowHandle_)
{
	UINT createDeviceFlags = 0;
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;	// �f�o�b�N���C���[���T�|�[�g����t���O
#endif
	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE,
	};
	UINT numDriverTypes = ARRAYSIZE(driverTypes);

	D3D_FEATURE_LEVEL featureLevel = D3D_FEATURE_LEVEL_11_0;

	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
	};
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);

	RECT rc;
	GetWindowRect(windowHandle_, &rc);

	auto width = rc.right - rc.left;
	auto height = rc.bottom - rc.top;

	//�f�o�C�X�ƃX���b�v�`�F�[���̍쐬
	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Width = width;
	sd.BufferDesc.Height = height;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 0;
	sd.BufferDesc.RefreshRate.Denominator = 0;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = windowHandle_;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = true;
	sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

	HRESULT result;

	for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
	{
		auto driverType = driverTypes[driverTypeIndex];
		result = D3D11CreateDeviceAndSwapChain(nullptr, driverType, nullptr, createDeviceFlags, featureLevels, numFeatureLevels,
		D3D11_SDK_VERSION, &sd, &swapChain_, &device_, &featureLevel, &context_);

		if (SUCCEEDED(result))
			break;
	}
	if (FAILED(result))
		return false;

	//�����_�[�^�[�Q�b�g�̍쐬
	swapChain_->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)backBuffer_.GetAddressOf());
	result = device_->CreateRenderTargetView(backBuffer_.Get(), nullptr, renderTarget_.GetAddressOf());
	
	if (FAILED(result))
		return false;

	//�X�e���V���r���[�̍쐬
	D3D11_TEXTURE2D_DESC dd;
	dd.Width = width;
	dd.Height = height;
	dd.MipLevels = 1;
	dd.ArraySize = 1;
	dd.Format = DXGI_FORMAT_D32_FLOAT;
	dd.SampleDesc.Count = 1;
	dd.SampleDesc.Quality = 0;
	dd.Usage = D3D11_USAGE_DEFAULT;
	dd.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	dd.CPUAccessFlags = 0;
	dd.MiscFlags = 0;
	result = device_->CreateTexture2D(&dd, nullptr, depthStencil_.GetAddressOf());

	if (FAILED(result))
		return false;

	result = device_->CreateDepthStencilView(depthStencil_.Get(), nullptr, depthStencilView_.GetAddressOf());

	if (FAILED(result))
		return false;

	//�����_�[�^�[�Q�b�g�ƃX�e���V���r���[�̐ݒ�
	context_->OMSetRenderTargets(1, renderTarget_.GetAddressOf(), depthStencilView_.Get());

	//�r���[�|�[�g�̐ݒ�
	D3D11_VIEWPORT vp;
	vp.Width = (float)width;
	vp.Height = (float)height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	context_->RSSetViewports(1, &vp);

	//���X�^���C�Y�X�e�[�g
	D3D11_RASTERIZER_DESC rdc;
	ZeroMemory(&rdc, sizeof(rdc));
	rdc.CullMode = D3D11_CULL_NONE;
	rdc.FillMode = D3D11_FILL_SOLID;
	rdc.FrontCounterClockwise = true;

	//���X�^���C�Y�X�e�[�g�̍쐬
	result = device_->CreateRasterizerState(&rdc, &rasterizeState_);

	if (FAILED(result))
		return false;

	context_->RSSetState(rasterizeState_.Get());

	spriteBach_.reset(new DirectX::SpriteBatch(context_.Get()));
	commonState_.reset(new DirectX::CommonStates(device_.Get()));
	factory_.reset(new DirectX::DGSLEffectFactory(device_.Get()));
	factory_->SetDirectory(L"Resources\\CMO");

	return true;
}

/////////////////////////////////////////////////////
// Name : ClearBuffer
//
// Over View : �o�b�t�@�̏�����
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void Graphics::ClearBuffer()
{
	float color[4] = { 0,0,0,1 };
	context_->ClearRenderTargetView(renderTarget_.Get(), color);
	context_->ClearDepthStencilView(depthStencilView_.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
}

/////////////////////////////////////////////////////
// Name : Present
//
// Over View : �o�b�t�@�̓���ւ�
//
// Argument : ����
//
// Return : ����
/////////////////////////////////////////////////////
void Graphics::Present()
{
	swapChain_->Present(0, 0);
}

/////////////////////////////////////////////////////
// Name : Device
//
// Over View : �f�o�C�X�̎擾
//
// Argument : ����
//
// Return : Device
/////////////////////////////////////////////////////
ID3D11Device * Graphics::Device()
{
	return device_.Get();
}

/////////////////////////////////////////////////////
// Name : Context
//
// Over View : �R���e�L�X�g�̎擾
//
// Argument : ����
//
// Return : Context
/////////////////////////////////////////////////////
ID3D11DeviceContext * Graphics::Context()
{
	return context_.Get();
}
