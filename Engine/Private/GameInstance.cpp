#include "GameInstance.h"
#include "Graphic_Device.h"

Engine::GameInstance::GameInstance()
{
}

Engine::GameInstance::~GameInstance()
{
    delete gd;
}

HRESULT Engine::GameInstance::Initialize(HINSTANCE _hInst, const GRAPHICDESC& _GraphicDesc, _Inout_ ComPtr<ID3D11Device>& _Device, _Inout_ ComPtr<ID3D11DeviceContext>& _Context)
{
    //FAILED_RETURN(GRAPHIC->Initialize(_GraphicDesc.hWnd, _GraphicDesc.WinMode, _GraphicDesc.ViewportSizeX, _GraphicDesc.ViewportSizeY, _Device, _Context), E_FAIL);
    gd = new Graphic_Device;
    gd->Initialize(_GraphicDesc.hWnd, _GraphicDesc.WinMode, _GraphicDesc.ViewportSizeX, _GraphicDesc.ViewportSizeY, _Device, _Context);
    

    return S_OK;
}

void Engine::GameInstance::Tick(_float fTimeDelta)
{
}

HRESULT Engine::GameInstance::ClearBackBuffer(Engine::_float4 _ClearColor)
{
    return S_OK;// GRAPHIC->ClearBackBuffer(_ClearColor);
}

HRESULT Engine::GameInstance::ClearDepthStencilView()
{
    return S_OK;// GRAPHIC->ClearDepthStencilView();
}

HRESULT Engine::GameInstance::Present()
{
    return S_OK;// GRAPHIC->Present();
}
