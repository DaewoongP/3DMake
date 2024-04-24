#include "GameInstance.h"
#include "Graphic_Device.h"

IMPLEMENT_SINGLETON(Engine::GameInstance)

Engine::GameInstance::GameInstance()
{
}

Engine::GameInstance::~GameInstance()
{
}

HRESULT Engine::GameInstance::Initialize(HINSTANCE _hInst, const GRAPHICDESC& _GraphicDesc, _Inout_ ComPtr<ID3D11Device>& _Device, _Inout_ ComPtr<ID3D11DeviceContext>& _Context)
{
    FAILED_RETURN(GRAPHIC->Initialize(_GraphicDesc.hWnd, _GraphicDesc.WinMode, _GraphicDesc.ViewportSizeX, _GraphicDesc.ViewportSizeY, _Device, _Context), E_FAIL);
    
    return S_OK;
}

void Engine::GameInstance::Tick(_float fTimeDelta)
{
}

HRESULT Engine::GameInstance::ClearBackBuffer(Engine::_float4 _ClearColor)
{
    return GRAPHIC->ClearBackBuffer(_ClearColor);
}

HRESULT Engine::GameInstance::ClearDepthStencilView()
{
    return GRAPHIC->ClearDepthStencilView();
}

HRESULT Engine::GameInstance::Present()
{
    return GRAPHIC->Present();
}

void Engine::GameInstance::Release()
{
    GET_SINGLE(GameInstance)->DestroyInstance();

    GET_SINGLE(Graphic_Device)->DestroyInstance();
}
