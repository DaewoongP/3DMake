#include "LevelPlay1.h"

HRESULT Client::LevelPlay1::Initialize()
{
	return S_OK;
}

void Client::LevelPlay1::Tick(_float _timeDelta)
{
	DebugFunc::Text("Play1 - Level", _timeDelta);
}
