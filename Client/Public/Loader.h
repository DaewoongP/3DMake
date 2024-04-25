#pragma once
#include "Engine_Defines.h"
#include "Client_Defines.h"

BEGIN(Client)

class Loader
{
public:
	Loader() = default;
	~Loader();
public:
	_bool GetFinished() const { return mFinished; }

public:
	HRESULT Initialize(LevelType _levelType);
	HRESULT Loading();

private:
	HRESULT LoadingForLogo();

private:
	HANDLE				mhThread;
	CRITICAL_SECTION	mCriticalSection;

private:
	LevelType			mNextLevelType;
	_tchar				mLoading[MAX_PATH];
	_bool				mFinished;
};

END