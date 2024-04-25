#include "MainApp.h"

USING(Engine)

HRESULT Client::MainApp::Initialize()
{
	GRAPHICDESC		graphicDesc;
	ZeroMemory(&graphicDesc, sizeof(GRAPHICDESC));

	graphicDesc.hWnd = ghWnd;
	graphicDesc.ViewportSizeX = gWinSizeX;
	graphicDesc.ViewportSizeY = gWinSizeY;
	graphicDesc.WinMode = GRAPHICDESC::WINMODE::WM_WIN;

	FAILED_RETURN(GAME->Initialize(ghInst, graphicDesc, mDevice, mDeviceContext), E_FAIL);

#ifdef _DEBUG
	FAILED_RETURN(GAME->AddFont(mDevice, mDeviceContext, TEXT("Font_135"), TEXT("../../Resource/Font/135ex.spritefont")), E_FAIL);
#endif // _DEBUG

	return S_OK;
}

void Client::MainApp::Tick(_float _timeDelta)
{
	GAME->Tick(_timeDelta);
}
