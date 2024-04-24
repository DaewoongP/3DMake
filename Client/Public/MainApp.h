#pragma once
#include "GameInstance.h"
#include "Client_Defines.h"

BEGIN(Client)

class MainApp
{
	UNIQUE_CLASS(MainApp, Initialize)
public:
	MainApp();
	~MainApp();

public:
	HRESULT Initialize();
	void Tick(Engine::_float _timeDelta);
	HRESULT Render();

private:
	ComPtr<ID3D11Device>		mDevice;
	ComPtr<ID3D11DeviceContext>	mDeviceContext;

#ifdef _DEBUG
private:
	Engine::_float	mTimeAcc;
	std::wstring	mFPS;
	Engine::_uint	mNumRenders;
#endif
};

END