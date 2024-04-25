#include "LevelLoading.h"
#include "Factory.h"
#include "GameInstance.h"

#include "LevelLogo.h"

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
	DebugFunc::Text("Loading...");

	if (false == GAME->GetDIKeyState(DIK_RETURN, Engine::InputDevice::KEY_DOWN))
		return;

	DebugFunc::Text("Enter!");

	if (false == mLoader->GetFinished())
		return;

	std::unique_ptr<Level> level;

	switch (mNextLevelType)
	{
	case LevelType::LOGO:
		level = Engine::Factory<Client::LevelLogo>::CreateUnique();
		break;
	}

	FAILED_RETURN(GAME->OpenLevel(static_cast<_uint>(mNextLevelType), std::move(level)), );
}
