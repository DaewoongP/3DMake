#pragma once
#include "Process.h"

namespace Client
{
	const unsigned int gWinSizeX = 1280;
	const unsigned int gWinSizeY = 720;

}

extern HINSTANCE ghInst;
extern HWND ghWnd;

#define CLIENT_FRAME		60.f