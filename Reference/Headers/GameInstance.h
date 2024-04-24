#pragma once
#include "Engine_Defines.h"

BEGIN(Engine)

class ENGINE_DLL GameInstance
{
	DECLARE_SINGLETON(GameInstance)
public:
	GameInstance();
	~GameInstance();

public:
	HRESULT Initialize(HINSTANCE _hInst, const GRAPHICDESC& _GraphicDesc, _Inout_ ComPtr<ID3D11Device>& _Device, _Inout_ ComPtr<ID3D11DeviceContext>& _Context);
	void Tick(_float fTimeDelta);

public: /* Graphic_Device */
	HRESULT ClearBackBuffer(Engine::_float4 _ClearColor);
	HRESULT ClearDepthStencilView();
	HRESULT Present();

private:
	class Graphic_Device* gd = nullptr;
};

END