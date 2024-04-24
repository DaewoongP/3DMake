#pragma once
namespace Engine
{
	typedef struct tagGraphicDesc
	{
		enum WINMODE { WM_FULL, WM_WIN, WM_END };
		HWND			hWnd;
		unsigned int	ViewportSizeX, ViewportSizeY;
		WINMODE			WinMode;
	}GRAPHICDESC;
}