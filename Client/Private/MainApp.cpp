#include "MainApp.h"

USING(Engine)

HRESULT Client::MainApp::Initialize()
{
	GRAPHICDESC		graphicDesc;
	ZeroMemory(&graphicDesc, sizeof(GRAPHICDESC));

	RECT rect = { 0 };
	GetClientRect(ghWnd, &rect);
	_int clientWidth = rect.right - rect.left;
	_int clientHeight = rect.bottom - rect.top;

	graphicDesc.hWnd = ghWnd;
	graphicDesc.ViewportSizeX = clientWidth;
	graphicDesc.ViewportSizeY = clientHeight;
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
