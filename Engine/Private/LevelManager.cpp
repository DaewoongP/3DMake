#include "LevelManager.h"

USING(Engine)

IMPLEMENT_SINGLETON(LevelManager)

HRESULT LevelManager::OpenLevel(_uint _levelIndex, std::unique_ptr<Level> _newLevel)
{
	return S_OK;
}
