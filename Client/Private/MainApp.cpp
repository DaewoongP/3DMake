#include "MainApp.h"

USING(Engine)

Client::MainApp::MainApp()
	: mDevice(nullptr)
	, mDeviceContext(nullptr)
#ifdef _DEBUG
	, mTimeAcc(0.f)
	, mFPS(TEXT(""))
	, mNumRenders(0)
#endif // _DEBUG
{
}

Client::MainApp::~MainApp()
{
	GAME->Release();
}

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
	FAILED_RETURN(GAME->AddFont(mDevice, mDeviceContext, TEXT("Font_135"), TEXT("../Bin/Resources/Fonts/135ex.spritefont")), E_FAIL);
#endif // _DEBUG

	return S_OK;
}

void Client::MainApp::Tick(_float _timeDelta)
{
#ifdef _DEBUG
	mTimeAcc += _timeDelta;
#endif

	GAME->Tick(_timeDelta);
}

HRESULT Client::MainApp::Render()
{
	//FAILED_RETURN(GAME->ClearBackBuffer(_float4(0.f, 0.f, 1.f, 1.f)), E_FAIL);
	//FAILED_RETURN(GAME->ClearDepthStencilView(), E_FAIL);
	//FAILED_RETURN(m_pRenderer->Draw_RenderGroup(), E_FAIL);
	//FAILED_RETURN(GAME->Render_Level(), E_FAIL);


#ifdef _DEBUG
	//++mNumRenders;

	//if (mTimeAcc >= 1.f)
	//{
	//	mFPS = TEXT("fps : ") + std::to_wstring(mNumRenders);

	//	mNumRenders = 0;
	//	mTimeAcc = 0;
	//}
	//GAME->RenderFont(TEXT("Font_135"), mFPS, _float2(0.f, 0.f));

#endif

	//FAILED_RETURN(GAME->Present(), E_FAIL);

	return S_OK;
}
