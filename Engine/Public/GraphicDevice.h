#pragma once
#include "Engine_Defines.h"

BEGIN(Engine)

class GraphicDevice
{
	DECLARE_SINGLETON(GraphicDevice)
public:
	GraphicDevice() = default;
	~GraphicDevice() = default;

public:
	HRESULT Initialize(HWND _hWnd, GRAPHICDESC::WINMODE _winMode,
		_uint _winCX, _uint _winCY, _Inout_ ComPtr<ID3D11Device>& _device,
		_Inout_ ComPtr<ID3D11DeviceContext>& _deviceContext);
	HRESULT ClearBackBuffer(Engine::_float4 _clearColor);
	HRESULT ClearDepthStencilView();
	HRESULT Present();

private:
	ComPtr<ID3D11Device>				mDevice;
	ComPtr<ID3D11DeviceContext>			mDeviceContext;
	ComPtr<IDXGISwapChain>				mSwapChain;
	ComPtr<ID3D11RenderTargetView>		mBackBufferRTV;
	ComPtr<ID3D11DepthStencilView>		mDepthStencilView;

private:
	HRESULT ReadySwapChain(HWND hWnd, GRAPHICDESC::WINMODE _winMode, _uint _winCX, _uint _winCY);
	HRESULT ReadyBackBufferRenderTargetView();
	HRESULT ReadyDepthStencilRenderTargetView(_uint _winCX, _uint _winCY);
};

END

#define GRAPHIC		GET_SINGLE(GraphicDevice)