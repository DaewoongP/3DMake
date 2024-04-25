#pragma once
#include "Engine_Defines.h"

BEGIN(Engine)

class ENGINE_DLL Level abstract
{
public:
	virtual HRESULT Initialize();
	virtual void Tick(_float _timeDelta);
	virtual HRESULT Render();
};

END