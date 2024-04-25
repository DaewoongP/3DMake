#include "Composite.h"
#include "GameInstance.h"
#include "LevelManager.h"
USING(Engine)
Composite::Composite()
	: Component()
{
}

Composite::Composite(const Composite& rhs)
	: Component(rhs)
{
}

Composite::~Composite()
{
}

HRESULT Composite::Initialize_Prototype()
{
	__super::Initialize_Prototype();

	return S_OK;
}

HRESULT Composite::Initialize(void* _arg)
{
	__super::Initialize(_arg);

	return S_OK;
}

void Composite::Tick(_float _timeDelta)
{
	for (auto& component : mComponents)
	{
		component.second->Tick(_timeDelta);
	}
}

void Composite::LateTick(_float _timeDelta)
{
	for (auto& component : mComponents)
	{
		component.second->LateTick(_timeDelta);
	}
}


std::shared_ptr<Component> Composite::AddComponent(const std::wstring& _prototypeKey, const std::wstring& _componentKey, void* _arg, _int _levelIndex)
{
	// _levelIndex가 -1이라면 현재 레벨 인덱스를 알아서 넣어준다.
	if (-1 == _levelIndex)
	{
		_levelIndex = LEVEL->GetCurrentLevelIndex();
	}

	// 컴포넌트 중복성 검사
	NULL_CHECK_RETURN_MSG(!FindComponent(_componentKey), std::shared_ptr<Component>(), TEXT("Engine::Composite::AddComponent\nexisting component"));

	// Clone component
	std::shared_ptr<Component> component = GAME->CloneComponent(_levelIndex, _prototypeKey, _arg);
	if (nullptr == component)
		return std::shared_ptr<Component>();

	// 컴포넌트 추가 후 반환
	mComponents.emplace(_componentKey, component);
	return component;
}

std::shared_ptr<Component> Composite::GetComponent(const std::wstring& _key)
{
	return FindComponent(_key);
}

HRESULT Composite::RemoveComponent(const std::wstring& _key)
{
	return E_NOTIMPL;
}

std::shared_ptr<Component> Composite::FindComponent(const std::wstring& _key)
{
	auto	iter = mComponents.find(_key);

	if (iter == mComponents.end())
		return nullptr;

	return iter->second;
}
