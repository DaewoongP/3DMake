#include "Timer.h"

USING(Engine)

Timer::Timer()
	: mTimeDelta(0.f)
{
	ZeroMemory(&mFrameTime, sizeof(LARGE_INTEGER));
	ZeroMemory(&mFixTime, sizeof(LARGE_INTEGER));
	ZeroMemory(&mLastTime, sizeof(LARGE_INTEGER));
	ZeroMemory(&mCpuTick, sizeof(LARGE_INTEGER));
}

HRESULT Timer::Initialize()
{
	QueryPerformanceCounter(&mFrameTime);
	QueryPerformanceCounter(&mLastTime);
	QueryPerformanceCounter(&mFixTime);
	QueryPerformanceFrequency(&mCpuTick);

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
