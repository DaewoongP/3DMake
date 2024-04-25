#include "LevelLogo.h"
#include "GameInstance.h"
#include "Factory.h"
#include "LevelLoading.h"

HRESULT Client::LevelLogo::Initialize()
{
	return S_OK;
}

void Client::LevelLogo::Tick(_float _timeDelta)
{
	DebugFunc::Text("Logo - Level", _timeDelta);

	if (GAME->GetDIKeyState(DIK_RETURN, Engine::InputDevice::KEY_DOWN))
	{
		DebugFunc::Text("Enter!");
		FAILED_RETURN(GAME->OpenLevel(static_cast<_uint>(LevelType::LOADING), 
			Engine::Factory<Client::LevelLoading>::CreateUnique(LevelType::PLAY1)), );
	}
}
