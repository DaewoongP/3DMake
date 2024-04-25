#pragma once
#include "GameInstance.h"
#include "Client_Defines.h"

BEGIN(Client)

class MainApp
{
public:
	MainApp() = default;
	~MainApp() = default;

public:
	HRESULT Initialize();
	void Tick(Engine::_float _timeDelta);
	HRESULT Render();

private:
	ComPtr<ID3D11Device>		mDevice;
	ComPtr<ID3D11DeviceContext>	mDeviceContext;
};

END