#pragma once
#include "Engine_Defines.h"
#include "Client_Defines.h"

BEGIN(Client)

class Loader
{
public:
	HRESULT Initialize(LevelType _levelType);
	HRESULT Loading();

private:
	HANDLE				m_hThread = { 0 };
	CRITICAL_SECTION	m_Critical_Section;

private:
	LevelType				m_eNextLevelID;
	_tchar				m_szLoading[MAX_PATH] = TEXT("");
	_bool				m_isFinished = { false };
};

END