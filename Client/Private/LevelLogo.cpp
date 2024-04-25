#include "LevelLogo.h"

HRESULT Client::LevelLogo::Initialize()
{
	return S_OK;
}

void Client::LevelLogo::Tick(_float _timeDelta)
{
	DebugFunc::Text("Logo - Level", _timeDelta);
}
