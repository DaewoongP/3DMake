#pragma once
#include "Component.h"

BEGIN(Engine)

class ComponentManager
{
	DECLARE_SINGLETON(ComponentManager)
public:
	//HRESULT Initialize();

private:
	_umap<std::wstring, Component>	mComponents;
};

END