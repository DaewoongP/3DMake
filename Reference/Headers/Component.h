#pragma once
#include "Engine_Defines.h"

BEGIN(Engine)

class ENGINE_DLL Component : std::enable_shared_from_this<Component>
{
public:
	Component();
	Component(const Component& rhs);
	virtual ~Component();

	virtual HRESULT Initialize_Prototype() { return S_OK; }
	virtual HRESULT Initialize(void* _arg) { return S_OK; }
	virtual void Tick(_float _timeDelta) {}
	virtual void LateTick(_float _timeDelta) {}

public:
	virtual std::shared_ptr<Component> Clone(void* _arg) = 0;
	_bool IsCloned() { return mIsCloned; }

protected:
	ComPtr<ID3D11Device> GetDevice() { return mDevice; }
	ComPtr<ID3D11DeviceContext> GetDeviceContext() { return mDeviceContext; }

private:
	ComPtr<ID3D11Device>		mDevice = { nullptr };
	ComPtr<ID3D11DeviceContext> mDeviceContext = { nullptr };
	_bool						mIsCloned = { false };
};

END