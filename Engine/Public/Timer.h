#pragma once
#include "Engine_Defines.h"

BEGIN(Engine)

class Timer
{
public:
	_float	GetTimeDelta() const { return mTimeDelta; }

public:
	HRESULT		InitializePrototype();
	void		Tick();

private:
	LARGE_INTEGER			mFrameTime;
	LARGE_INTEGER			mFixTime;
	LARGE_INTEGER			mLastTime;
	LARGE_INTEGER			mCpuTick;

	_float					mTimeDelta;
};

END
