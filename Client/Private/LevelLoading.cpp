#include "LevelLoading.h"
#include "Factory.h"
#include "GameInstance.h"

#include "LevelLogo.h"
#include "LevelPlay1.h"

Client::LevelLoading::~LevelLoading()
{
}

HRESULT Client::LevelLoading::Initialize(LevelType _levelType)
{
	mNextLevelType = _levelType;

	mLoader = Engine::Factory<Client::Loader>::CreateUnique(_levelType);

	return S_OK;
}

void Client::LevelLoading::Tick(_float _timeDelta)
{
	DebugFunc::Text("Loading...", _timeDelta);

	if (false == mLoader->GetFinished())
		return;

	std::unique_ptr<Level> level;

	switch (mNextLevelType)
	{
	case LevelType::LOGO:
		level = Engine::Factory<Client::LevelLogo>::CreateUnique();
		break;
	case LevelType::PLAY1:
		level = Engine::Factory<Client::LevelPlay1>::CreateUnique();
		break;
	}

	FAILED_RETURN(GAME->OpenLevel(static_cast<_uint>(mNextLevelType), std::move(level)), );
}
