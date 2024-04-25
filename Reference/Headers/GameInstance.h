#pragma once
#include "Engine_Defines.h"
#include "InputDevice.h"

BEGIN(Engine)

class ENGINE_DLL GameInstance
{
	DECLARE_SINGLETON(GameInstance)
public:
	GameInstance() = default;
	~GameInstance() = default;

public: /* Device & Context */
	ComPtr<ID3D11Device> GetDevice() const;
	ComPtr<ID3D11DeviceContext> GetDeviceContext() const;

public:
	HRESULT Initialize(HINSTANCE _hInst, const GRAPHICDESC& _graphicDesc, _Inout_ ComPtr<ID3D11Device>& _device, _Inout_ ComPtr<ID3D11DeviceContext>& _deviceContext);
	void Tick(_float _timeDelta);

public: /* GraphicDevice */
	HRESULT RenderBegin(_float4 _clearColor);
	HRESULT RenderEnd();

public: /* TimerManager */
	_float		GetTimer(const std::wstring& _timerTag);
	void		SetTimer(const std::wstring& _timerTag);
	HRESULT		AddTimer(const std::wstring& _timerTag);

public: /* InputDevice */
	_bool		GetDIKeyState(_ubyte _keyID, InputDevice::KEYSTATE _state = InputDevice::KEY_PRESSING);
	_bool		GetDIMouseState(InputDevice::MOUSEKEYSTATE _mouseID, InputDevice::KEYSTATE _state = InputDevice::KEY_PRESSING);
	_long		GetDIMouseMove(InputDevice::MOUSEMOVESTATE _mouseMoveID);

public: /* FontManager */
	HRESULT AddFont(ComPtr<ID3D11Device> _device, ComPtr<ID3D11DeviceContext> _deviceContext, const std::wstring& _fontTag, const std::wstring& _fontFilePath);
	HRESULT RenderFont(const std::wstring& _fontTag, const std::wstring& _text, const _float2& _position, _fvector _color = XMVectorSet(1.f, 1.f, 1.f, 1.f), _float _rotation = 0.f, const _float2& _origin = _float2(0.f, 0.f), _float _scale = 1.f);

public: /* ImguiManager */
	void ImguiBegin();
	void ImguiEnd();

public: /* LevelManager */
	HRESULT OpenLevel(_uint _levelIndex, std::unique_ptr<class Level>&& _newLevel);

public: /* ComponentManager */
	HRESULT AddPrototype(_uint _levelIndex, const std::wstring& _prototypeTag, std::shared_ptr<class Component> _prototype);
	std::shared_ptr<class Component> CloneComponent(_uint _levelIndex, const std::wstring& _prototypeTag, void* _arg);

private:
	HRESULT ClearLevelResources(_uint _preLevelIndex);

public:
	static void Release();
};

END

#define GAME		GET_SINGLE(GameInstance)