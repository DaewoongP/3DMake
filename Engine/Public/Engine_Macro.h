#pragma once
///////////////////////// My Macros //////////////////////////////////
#define			PURE							= 0
#define			CharToWChar(_pChar, _pWchar)	MultiByteToWideChar(CP_ACP, 0, _pChar, MAX_PATH, _pWchar, MAX_PATH);
#define         WCharToChar(_pWchar, _pChar)    WideCharToMultiByte(CP_ACP, 0, _pWchar, -1, _pChar, MAX_PATH, nullptr, nullptr);
#define D3DCOLOR_ARGB(a,r,g,b) \
    ((D3DCOLOR)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))
///////////////////////// default Macros /////////////////////////////


#ifndef			MSG_BOX
#define			MSG_BOX(_message)			MessageBox(nullptr, TEXT(_message), L"System Message", MB_OK)
#endif

#define			BEGIN(NAMESPACE)		namespace NAMESPACE {
#define			END						}

#define			USING(NAMESPACE)	using namespace NAMESPACE;

#ifdef	ENGINE_EXPORTS
#define ENGINE_DLL		_declspec(dllexport)
#else
#define ENGINE_DLL		_declspec(dllimport)
#endif

#define NULL_RETURN( _ptr, _return)	\
	{if( _ptr == 0){return _return;}}

#define NULL_CHECK( _ptr)	\
	{if( _ptr == 0){__debugbreak();return;}}

#define NULL_CHECK_RETURN( _ptr, _return)	\
	{if( _ptr == 0){__debugbreak();return _return;}}

#define NULL_CHECK_MSG( _ptr, _message )		\
	{if( _ptr == 0){MessageBox(nullptr, _message, L"System Message",MB_OK);__debugbreak();}}

#define NULL_CHECK_RETURN_MSG( _ptr, _return, _message )	\
	{if( _ptr == 0){MessageBox(nullptr, _message, L"System Message",MB_OK);__debugbreak();return _return;}}


#define FAILED_RETURN(_hr, _return)	if( ((HRESULT)(_hr)) < 0 )	\
	{ return _return; }

#define FAILED_CHECK(_hr)	if( ((HRESULT)(_hr)) < 0 )	\
	{ MessageBoxW(nullptr, L"Failed", L"System Error",MB_OK); __debugbreak(); return E_FAIL;}

#define FAILED_CHECK_RETURN(_hr, _return)	if( ((HRESULT)(_hr)) < 0 )		\
	{ MessageBoxW(nullptr, L"Failed", L"System Error",MB_OK); __debugbreak(); return _return;}

#define FAILED_CHECK_MSG( _hr, _message)	if( ((HRESULT)(_hr)) < 0 )	\
	{ MessageBoxW(nullptr, _message, L"System Message",MB_OK); __debugbreak();return E_FAIL;}

#define FAILED_CHECK_RETURN_MSG( _hr, _return, _message)	if( ((HRESULT)(_hr)) < 0 )	\
	{ MessageBoxW(nullptr, _message, L"System Message",MB_OK); __debugbreak();return _return;}



#define DECLARE_SINGLETON(classname)				\
public:												\
    static classname* GetInstance()					\
    {												\
        static classname sInstance;					\
        return &sInstance;							\
    }

#define GET_SINGLE(classname)    classname::GetInstance()