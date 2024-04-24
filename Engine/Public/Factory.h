#pragma once
#include "Engine_Defines.h"

BEGIN(Engine)

template<typename T>
class Factory
{
public:
	Factory() = default;
	~Factory() = default;

public:
	/*static CObj* Create()
	{
		CObj* pObj = new T;
		pObj->Initialize();
		return pObj;
	}*/
};

END