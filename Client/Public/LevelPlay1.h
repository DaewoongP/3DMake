#pragma once
#include "Level.h"
#include "Client_Defines.h"

BEGIN(Client)

class LevelPlay1 : public Engine::Level
{
public:
	LevelPlay1() = default;
	~LevelPlay1() = default;

public:
	virtual HRESULT Initialize() override;
	virtual void Tick(_float _timeDelta) override;
};

END