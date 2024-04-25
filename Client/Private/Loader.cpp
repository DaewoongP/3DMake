#include "Loader.h"
#include "Factory.h"

_uint WINAPI Thread_Main(void* _arg)
{
	using namespace Client;

	Loader* loader = reinterpret_cast<Loader*>(_arg);

	if (FAILED(loader->Loading()))
		return 0;

	return 0;
}

Client::Loader::~Loader()
{
	WaitForSingleObject(mhThread, INFINITE);

	DeleteCriticalSection(&mCriticalSection);
	CloseHandle(mhThread);
}

HRESULT Client::Loader::Initialize(LevelType _levelType)
{
	mNextLevelType = _levelType;

	InitializeCriticalSection(&mCriticalSection);

	mhThread = (HANDLE)_beginthreadex(nullptr, 0, Thread_Main, this, 0, nullptr);

	if (0 == mhThread)
	{
		MSG_BOX("Loader::Initialize\n Failed beginthreadex");
		__debugbreak();
		return E_FAIL;
	}
	
	return S_OK;
}

HRESULT Client::Loader::Loading()
{
	FAILED_CHECK_RETURN_MSG(CoInitializeEx(nullptr, 0), E_FAIL, TEXT("Loader::Loading\n Failed"));

	EnterCriticalSection(&mCriticalSection);

	HRESULT	hr = 0;

	switch (mNextLevelType)
	{
	case LevelType::LOGO:
		hr = LoadingForLogo();
		break;
	}

	LeaveCriticalSection(&mCriticalSection);

	FAILED_RETURN(hr, E_FAIL);

	return S_OK;
}

HRESULT Client::Loader::LoadingForLogo()
{

	mFinished = true;

	return S_OK;
}
