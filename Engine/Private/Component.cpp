#include "Component.h"
#include "GameInstance.h"
USING(Engine)

Component::Component()
{
	mDevice = GAME->GetDevice();
	mDeviceContext = GAME->GetDeviceContext();
}

Component::Component(const Component& rhs)
	: mDevice(rhs.mDevice)
	, mDeviceContext(rhs.mDeviceContext)
	, mIsCloned(true)
{
	
}

Component::~Component()
{
}
