#include "LevelPlay1.h"
#include "GameInstance.h"

void Client::LevelPlay1::Test(void* arg)
{
	DebugFunc::Text("Test Invoke");
}

HRESULT Client::LevelPlay1::Initialize()
{
	GAME->Invoke(std::bind(&Client::LevelPlay1::Test, this, std::placeholders::_1), nullptr, 0.3f);
	return S_OK;
}

void Client::LevelPlay1::Tick(_float _timeDelta)
{
	DebugFunc::Text("Play1 - Level", _timeDelta);
}
