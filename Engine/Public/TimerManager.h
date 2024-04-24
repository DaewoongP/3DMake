#pragma once
#include "Engine_Defines.h"

BEGIN(Engine)

class TimerManager
{
	DECLARE_SINGLETON(TimerManager)
public:
	TimerManager() = default;
	~TimerManager() = default;

public:
	_float		GetTimer(const std::wstring& _timerTag);
	void		SetTimer(const std::wstring& _timerTag);

public:
	HRESULT		AddTimer(const std::wstring& _timerTag);

private:
	std::shared_ptr<class Timer> FindTimer(const std::wstring& _timerTag);

private:
	_umap<std::wstring, std::shared_ptr<class Timer>>	mTimers;
};

END

#define TIMER		GET_SINGLE(TimerManager)