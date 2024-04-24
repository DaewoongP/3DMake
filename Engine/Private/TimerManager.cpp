#include "TimerManager.h"
#include "Timer.h"

USING(Engine)

IMPLEMENT_SINGLETON(TimerManager)

_float TimerManager::GetTimer(const std::wstring& _timerTag)
{
	std::shared_ptr<class Timer> timer = FindTimer(_timerTag);
	if (nullptr == timer)
		return 0.0;

	return timer->GetTimeDelta();
}

void TimerManager::SetTimer(const std::wstring& _timerTag)
{
	std::shared_ptr<class Timer> timer = FindTimer(_timerTag);
	if (nullptr == timer)
		return;

	timer->Tick();
}

HRESULT TimerManager::AddTimer(const std::wstring& _timerTag)
{
	std::shared_ptr<class Timer> timer = FindTimer(_timerTag);

	if (nullptr != timer)
	{
		MSG_BOX("TimerManager::AddTimer\n Already Have TimerTag");
		__debugbreak();
		return E_FAIL;
	}
	
	timer = std::make_shared<class Timer>();
	FAILED_CHECK_RETURN_MSG(timer->Initialize(), E_FAIL, TEXT("TimerManager::AddTimer\nFailed Create Timer"));

	mTimers.emplace(_timerTag, timer);

	return S_OK;
}

std::shared_ptr<class Timer> TimerManager::FindTimer(const std::wstring& _timerTag)
{
	auto		iter = mTimers.find(_timerTag);

	if (iter == mTimers.end())
		return nullptr;
	
	return iter->second;
}
