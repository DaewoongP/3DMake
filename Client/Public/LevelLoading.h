#pragma once
#include "Level.h"
#include "Loader.h"

BEGIN(Client)

class LevelLoading : public Engine::Level
{
public:
	LevelLoading() = default;
	~LevelLoading() = default;

public:
	HRESULT Initialize(LevelType _levelType);
	virtual void Tick(_float _timeDelta) override;

private:
	std::unique_ptr<Loader>	mLoader;
	LevelType				mNextLevelType;
};

END