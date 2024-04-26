#include "Timer.h"

USING(Engine)

HRESULT Timer::InitializePrototype()
{
	QueryPerformanceCounter(&mFrameTime);
	QueryPerformanceCounter(&mLastTime);
	QueryPerformanceCounter(&mFixTime);
	QueryPerformanceFrequency(&mCpuTick);
	mTimeDelta = 0.f;

	return S_OK;
}

void Timer::Tick()
{
	QueryPerformanceCounter(&mFrameTime);

	if (mFrameTime.QuadPart - mFixTime.QuadPart >= mCpuTick.QuadPart)
	{
		QueryPerformanceFrequency(&mCpuTick);
		mFixTime = mFrameTime;
	}

	mTimeDelta = ((mFrameTime.QuadPart) - (mLastTime.QuadPart)) / _float(mCpuTick.QuadPart);

	mLastTime = mFrameTime;
}
