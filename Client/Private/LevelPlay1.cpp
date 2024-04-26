#include "LevelPlay1.h"
#include "GameInstance.h"

HRESULT Client::LevelPlay1::Initialize()
{
	//GAME->Invoke(std::bind(&Client::LevelPlay1::Test, this, std::placeholders::_1), nullptr, 0.3f);
	return S_OK;
}

void Client::LevelPlay1::Tick(_float _timeDelta)
{
	DebugFunc::Text("Play1 - Level", _timeDelta);
}

std::unique_ptr<Client::LevelPlay1> Client::LevelPlay1::Create()
{
	auto instance = std::make_unique<Client::LevelPlay1>();
	FAILED_CHECK_RETURN_MSG(instance->Initialize(), nullptr, TEXT("Client::LevelPlay1::Create\n Failed"));
	return instance;
}
