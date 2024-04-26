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

	typedef struct tagVertex_Position
	{
		XMFLOAT3		vPosition;		
	}VTXPOS;

	typedef struct ENGINE_DLL tagVertex_Position_Declaration
	{
		static const unsigned int				iNumElements = { 1 };
		static const D3D11_INPUT_ELEMENT_DESC			Elements[1];
	}VTXPOS_DECL;
		

	typedef struct tagVertex_Position_TexCoord
	{
		XMFLOAT3		vPosition;
		XMFLOAT2		vTexCoord;
	}VTXPOSTEX;

	typedef struct ENGINE_DLL tagVertex_Position_TexCoord_Declaration
	{
		static const unsigned int				iNumElements = { 2 };
		static const D3D11_INPUT_ELEMENT_DESC			Elements[2];
	}VTXPOSTEX_DECL;


	typedef struct tagVertex_Cube
	{
		XMFLOAT3		vPosition;
		XMFLOAT3		vTexCoord;
	}VTXCUBE;

	typedef struct ENGINE_DLL tagVertex_Cube_Declaration
	{
		static const unsigned int				iNumElements = { 2 };
		static const D3D11_INPUT_ELEMENT_DESC			Elements[2];
	}VTXCUBE_DECL;


	typedef struct tagVertex_Position_Size
	{
		XMFLOAT3		vPosition;
		XMFLOAT2		vPSize;
	}VTXPOINT;


	typedef struct tagVertex_Position_Normal_TexCoord
	{
		XMFLOAT3		vPosition;
		XMFLOAT3		vNormal;
		XMFLOAT2		vTexCoord;
	}VTXPOSNORTEX;

	typedef struct ENGINE_DLL tagVertex_Position_Normal_TexCoord_Declaration
	{
		static const unsigned int				iNumElements = { 3 };
		static const D3D11_INPUT_ELEMENT_DESC	Elements[iNumElements];
	}VTXPOSNORTEX_DECL;

	typedef struct tagVertex_Mesh
	{
		XMFLOAT3		vPosition;
		XMFLOAT3		vNormal;
		XMFLOAT2		vTexCoord;
		XMFLOAT3		vTangent;
	}VTXMESH;

	typedef struct ENGINE_DLL tagVertex_Mesh_Declaration
	{
		static const unsigned int				iNumElements = { 4 };
		static const D3D11_INPUT_ELEMENT_DESC			Elements[4];
	}VTXMESH_DECL;


	typedef struct tagVertex_AnimMesh
	{
		XMFLOAT3		vPosition;
		XMFLOAT3		vNormal;
		XMFLOAT2		vTexCoord;
		XMFLOAT3		vTangent;
		XMUINT4			vBlendIndices;
		XMFLOAT4		vBlendWeights;
	}VTXANIMMESH;

	typedef struct ENGINE_DLL tagVertex_AnimMesh_Declaration
	{
		static const unsigned int				iNumElements = { 6 };
		static const D3D11_INPUT_ELEMENT_DESC			Elements[6];
	}VTXANIMMESH_DECL;

	typedef struct tagVertex_Instance
	{		
		XMFLOAT4		vRight; 
		XMFLOAT4		vUp;
		XMFLOAT4		vLook;
		XMFLOAT4		vTranslation;
	}VTXINSTANCE;

	typedef struct ENGINE_DLL tagVertex_Rect_Instance_Declaration
	{
		static const unsigned int				iNumElements = { 6 };
		static const D3D11_INPUT_ELEMENT_DESC			Elements[6];
	}VTXRECTINSTANCE_DECL;

	typedef struct ENGINE_DLL tagVertex_Point_Instance_Declaration
	{
		static const unsigned int				iNumElements = { 6 };
		static const D3D11_INPUT_ELEMENT_DESC			Elements[6];
	}VTXPOINTINSTANCE_DECL;
}
