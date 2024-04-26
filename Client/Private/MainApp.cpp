#include "MainApp.h"
#include "LevelLogo.h"

USING(Engine)

HRESULT Client::MainApp::Initialize()
{
	//FAILED_CHECK_RETURN_MSG(Test(), E_FAIL, TEXT("Test")); // hr는 HRESULT 타입의 변수입니다.
	//FAILED_CHECK_MSG(Test(), TEXT("Test"));
	//FAILED_CHECK(Test());
	GRAPHICDESC		graphicDesc;
	ZeroMemory(&graphicDesc, sizeof(GRAPHICDESC));

	RECT rect;
	ZeroMemory(&rect, sizeof(RECT));
	GetClientRect(ghWnd, &rect);
	_int clientWidth = rect.right - rect.left;
	_int clientHeight = rect.bottom - rect.top;

	graphicDesc.hWnd = ghWnd;
	graphicDesc.ViewportSizeX = clientWidth;
	graphicDesc.ViewportSizeY = clientHeight;
	graphicDesc.WinMode = GRAPHICDESC::WINMODE::WM_WIN;

	FAILED_RETURN(GAME->Initialize(ghInst, static_cast<_uint>(LevelType::LEVELEND), graphicDesc, mDevice, mDeviceContext), E_FAIL);
	FAILED_RETURN(GAME->OpenLevel(static_cast<_uint>(LevelType::LOGO), Factory<LevelLogo>::CreateUnique()), E_FAIL);

#ifdef _DEBUG
	FAILED_RETURN(GAME->AddFont(mDevice, mDeviceContext, TEXT("Font_135"), TEXT("../../Resource/Font/135ex.spritefont")), E_FAIL);
#endif // _DEBUG

	return S_OK;
}

void Client::MainApp::Tick(_float _timeDelta)
{
	GAME->Tick(_timeDelta);
}
