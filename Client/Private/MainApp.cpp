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

	graphicDesc.hWnd = ghWnd;
	graphicDesc.ViewportSizeX = gWinSizeX;
	graphicDesc.ViewportSizeY = gWinSizeY;
	graphicDesc.WinMode = GRAPHICDESC::WINMODE::WM_WIN;

	FAILED_RETURN(GAME->Initialize(ghInst, static_cast<_uint>(LevelType::TYPEEND), graphicDesc, mDevice, mDeviceContext), E_FAIL);
	FAILED_RETURN(GAME->OpenLevel(static_cast<_uint>(LevelType::LOGO), LevelLogo::Create()), E_FAIL);

#ifdef _DEBUG
	FAILED_RETURN(GAME->AddFont(mDevice, mDeviceContext, TEXT("Font_135"), TEXT("../../Resource/Font/135ex.spritefont")), E_FAIL);
#endif // _DEBUG

	return S_OK;
}

void Client::MainApp::Tick(_float _timeDelta)
{
	GAME->Tick(_timeDelta);
}

HRESULT Client::MainApp::Render()
{
	return GAME->Render();
}

std::unique_ptr<Client::MainApp> Client::MainApp::Create()
{
	auto instance = std::make_unique<Client::MainApp>();
	FAILED_CHECK_RETURN_MSG(instance->Initialize(), nullptr, TEXT("Client::MainApp::Create\n Failed"));
	return instance;
}
