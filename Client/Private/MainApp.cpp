#include "MainApp.h"

USING(Engine)

Client::MainApp::MainApp()
	: mDevice(nullptr)
	, mContext(nullptr)
{
}

Client::MainApp::~MainApp()
{
	GAME->Release();
}

HRESULT Client::MainApp::Initialize()
{
	Engine::GRAPHICDESC		GraphicDesc;
	ZeroMemory(&GraphicDesc, sizeof(Engine::GRAPHICDESC));

	GraphicDesc.hWnd = ghWnd;
	GraphicDesc.ViewportSizeX = gWinSizeX;
	GraphicDesc.ViewportSizeY = gWinSizeY;
	GraphicDesc.WinMode = Engine::GRAPHICDESC::WINMODE::WM_WIN;

	FAILED_RETURN(GAME->Initialize(ghInst, GraphicDesc, mDevice, mContext), E_FAIL);
	
	return S_OK;
}

void Client::MainApp::Tick(_float _TimeDelta)
{
	GAME->Tick(_TimeDelta);
}

HRESULT Client::MainApp::Render()
{
	FAILED_RETURN(GAME->ClearBackBuffer(_float4(0.f, 0.f, 1.f, 1.f)), E_FAIL);
	FAILED_RETURN(GAME->ClearDepthStencilView(), E_FAIL);
	//FAILED_RETURN(m_pRenderer->Draw_RenderGroup(), E_FAIL);
	//FAILED_RETURN(GAME->Render_Level(), E_FAIL);

	FAILED_RETURN(GAME->Present(), E_FAIL);

	return S_OK;
}
