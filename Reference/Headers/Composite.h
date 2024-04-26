#pragma once

#include "Component.h"

BEGIN(Engine)

class ENGINE_DLL Composite : public Component
{
public:
	Composite();
	Composite(const Composite& rhs);
	virtual ~Composite();

	virtual HRESULT Initialize_Prototype();
	virtual HRESULT Initialize(void* _arg);
	virtual void Tick(_float _timeDelta);
	virtual void LateTick(_float _timeDelta);

	std::shared_ptr<Component> AddComponent(const std::wstring& _prototypeKey, const std::wstring& _componentKey, void* _arg = nullptr, _int _levelIndex = -1);
	std::shared_ptr<Component> GetComponent(const std::wstring& _key);
	size_t RemoveComponent(const std::wstring& _key);

public:
	virtual std::shared_ptr<Component> Clone(void* _arg) = 0;

private:
	_umap<std::wstring, std::shared_ptr<Component>> mComponents;
};

END