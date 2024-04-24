#include "TimerManager.h"
#include "Timer.h"
#include "Factory.h"
USING(Engine)

IMPLEMENT_SINGLETON(TimerManager)

_float TimerManager::GetTimer(const std::wstring& _timerTag)
{
	std::shared_ptr<Timer> timer = FindTimer(_timerTag);
	if (nullptr == timer)
		return 0.0;

	return timer->GetTimeDelta();
}

void TimerManager::SetTimer(const std::wstring& _timerTag)
{
	std::shared_ptr<Timer> timer = FindTimer(_timerTag);
	if (nullptr == timer)
		return;

	timer->Tick();
}

HRESULT TimerManager::AddTimer(const std::wstring& _timerTag)
{
	std::shared_ptr<Timer> timer = FindTimer(_timerTag);

	if (nullptr != timer)
	{
		MSG_BOX("TimerManager::AddTimer\n Already Have TimerTag");
		__debugbreak();
		return E_FAIL;
	}
	
	mTimers.emplace(_timerTag, Factory<Timer>::CreateShared());

	return S_OK;
}

std::shared_ptr<Timer> TimerManager::FindTimer(const std::wstring& _timerTag)
{
	auto		iter = mTimers.find(_timerTag);

	if (iter == mTimers.end())
		return nullptr;
	
	return iter->second;
}
