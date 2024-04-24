#pragma once
#include "Engine_Defines.h"

BEGIN(Engine)

template<typename T>
class Factory
{
private:
	Factory() = default;
	~Factory() = default;

public:
	static std::shared_ptr<T> CreateShared()
	{
		std::shared_ptr<T> instance = std::make_shared<T>();
		FAILED_CHECK_RETURN_MSG(instance->Initialize(), nullptr, TEXT("Factory::CreateShared\n Failed"));
		return instance;
	}

	template<typename ...Args>
	static std::shared_ptr<T> CreateShared(Args&&... args)
	{
		std::shared_ptr<T> instance = std::make_shared<T>();
		FAILED_CHECK_RETURN_MSG(instance->Initialize(std::forward<Args>(args)...), nullptr, TEXT("Factory::CreateShared\n Failed"));
		return instance;
	}
};

END