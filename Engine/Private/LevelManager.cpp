#include "LevelManager.h"

USING(Engine)

IMPLEMENT_SINGLETON(LevelManager)

HRESULT LevelManager::OpenLevel(_uint _levelIndex, std::unique_ptr<Level>&& _newLevel)
{
	mLevelIndex = _levelIndex;

	mCurrentLevel.reset(_newLevel.get());

	return S_OK;
}

void LevelManager::Tick(_float _timeDelta)
{
	mCurrentLevel->Tick(_timeDelta);
}
