#pragma once
#include "Assimp_Defines.h"

BEGIN(ASSIMP)

class AIModel
{
public:
	enum class ModelType { NONANIM, ANIM, TYPE_END };

public:
	AIModel() = default;
	~AIModel() = default;

public:
	HRESULT Initialize(ModelType _modelType, const std::string& _modelFilePath, _fmatrix _pivotMatrix);

private:
	HRESULT ConvertBones(aiNode* _node, _uint _parentIndex, _Inout_ _uint* _childIndex, _bool _root = false);
	HRESULT SortNodes();
	HRESULT ConvertMeshes();
	HRESULT StoreMesh(const aiMesh* _aiMesh, _Inout_ Engine::MESH* _outMesh);
	HRESULT ConvertMaterials(ModelType _modelType, const _char* _modelFilePath);
	//HRESULT CopyMaterial();
	HRESULT ConvertAnimations();

private:
	HRESULT WriteFile(ModelType _modelType, const _tchar* _fileName);

private:
	const aiScene*					mAIScene;
	Assimp::Importer				mImporter;

private:
	std::vector<Engine::NODE>		mNodes;

private:
	Engine::MODEL					mModel;
	Engine::MESH*					mMesh;
	Engine::MATERIAL*				mMaterial;
	Engine::ANIMATION*				mAnimation;

private:
	_float4x4						mPivotMatrix;

public:
	static std::shared_ptr<AIModel> Create(ModelType _modelType, const std::string& _modelFilePath, _fmatrix _pivotMatrix);
};

END