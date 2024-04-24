#pragma once
#include "Engine_Defines.h"

BEGIN(Engine)

class Timer
{
	SHARED_CLASS(Timer, Initialize)
public:
	Engine::_float	GetTimeDelta() { return mTimeDelta; }

public:
	HRESULT		Initialize();
	void		Tick();

private:
	LARGE_INTEGER			mFrameTime;
	LARGE_INTEGER			mFixTime;
	LARGE_INTEGER			mLastTime;
	LARGE_INTEGER			mCpuTick;

	Engine::_float			mTimeDelta;
};

END
