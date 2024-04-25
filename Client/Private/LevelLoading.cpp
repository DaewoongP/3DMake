#include "LevelLoading.h"
#include "Factory.h"

HRESULT Client::LevelLoading::Initialize(LevelType _levelType)
{
	mNextLevelType = _levelType;

	mLoader = Engine::Factory<Client::Loader>::CreateUnique(_levelType);

	return S_OK;
}

void Client::LevelLoading::Tick(_float _timeDelta)
{
}
