#include "AIModel.h"

HRESULT ASSIMP::AIModel::Initialize(ModelType _modelType, const std::string& _modelFilePath, _fmatrix _pivotMatrix)
{
	_uint flag = 0;

	XMStoreFloat4x4(&mPivotMatrix, _pivotMatrix);

	if (ModelType::NONANIM == _modelType)
		flag = aiProcess_GlobalScale | aiProcess_ConvertToLeftHanded | aiProcessPreset_TargetRealtime_Fast | aiProcess_PreTransformVertices;
	else
		flag = aiProcess_GlobalScale | aiProcess_ConvertToLeftHanded | aiProcessPreset_TargetRealtime_Fast;

	mAIScene = mImporter.ReadFile(_modelFilePath, flag);

	if (FAILED(ConvertBones(mAIScene->mRootNode, 0, nullptr, true)))
		return E_FAIL;
	SortNodes();

	if (FAILED(ConvertMeshes()))
		return E_FAIL;

	/*if (FAILED(ConvertMaterials(_modelType, _modelFilePath.c_str())))
		return E_FAIL;

	if (FAILED(ConvertAnimations()))
		return E_FAIL;*/

	return S_OK;
}

HRESULT ASSIMP::AIModel::ConvertBones(aiNode* _node, _uint _parentIndex, _Inout_ _uint* _childIndex, _bool _root)
{
	Engine::NODE Node;
	ZeroMemory(&Node, sizeof(Engine::NODE));

	_tchar BoneName[MAX_PATH] = TEXT("");
	CharToWChar(_node->mName.data, BoneName);
	lstrcpy(Node.Name, BoneName);

	_float4x4 TransposeMatrix;
	memcpy(&TransposeMatrix, &_node->mTransformation, sizeof(_float4x4));
	XMStoreFloat4x4(&TransposeMatrix, XMMatrixTranspose(XMLoadFloat4x4(&TransposeMatrix)));
	memcpy(&Node.Transformation, &TransposeMatrix, sizeof(_float4x4));

	static _uint currenNodeIndex = 0;
	
	if (true == _root)
		Node.Parent = -1;
	else
	{
		*_childIndex = ++currenNodeIndex;
		Node.Parent = _parentIndex;
	}

	Node.NodeIndex = currenNodeIndex;
	Node.NumChildren = _node->mNumChildren;

	if (0 != _node->mNumChildren)
	{
		Node.Children = new _uint[_node->mNumChildren];
		ZeroMemory(Node.Children, sizeof(_uint) * _node->mNumChildren);
	}

	for (_uint i = 0; i < _node->mNumChildren; i++)
	{
		_uint retIndex = { 0 };
		ConvertBones(_node->mChildren[i], Node.NodeIndex, &retIndex);
		Node.Children[i] = retIndex;
	}

	mNodes.emplace_back(Node);

	return S_OK;
}

HRESULT ASSIMP::AIModel::SortNodes()
{
	std::sort(mNodes.begin(), mNodes.end(), [](const Engine::NODE& _sour, const Engine::NODE& _dest) {
		if (_sour.NodeIndex < _dest.NodeIndex)
			return true;
		else
			return false;
		});

	mModel.NumNodes = static_cast<_uint>(mNodes.size());

	return S_OK;
}

HRESULT ASSIMP::AIModel::ConvertMeshes()
{
	mModel.NumMeshes = mAIScene->mNumMeshes;

	mMesh = new Engine::MESH[mAIScene->mNumMeshes];
	ZeroMemory(mMesh, sizeof(Engine::MESH) * mAIScene->mNumMeshes);

	for (_uint i = 0; i < mAIScene->mNumMeshes; ++i)
	{
		Engine::MESH mesh;
		ZeroMemory(&mesh, sizeof(Engine::MESH));

		if (FAILED(StoreMesh(mAIScene->mMeshes[i], &mesh)))
		{
			MSG_BOX("Failed Store Mesh");
			return E_FAIL;
		}

		mMesh[i] = mesh;
	}

	return S_OK;
}

HRESULT ASSIMP::AIModel::StoreMesh(const aiMesh* _aiMesh, _Inout_ Engine::MESH* _outMesh)
{
	_outMesh->MaterialIndex = _aiMesh->mMaterialIndex;

	_tchar meshName[256] = TEXT("");
	CharToWChar(_aiMesh->mName.data, meshName);
	lstrcpy(_outMesh->Name, meshName);

	_outMesh->NumVertices = _aiMesh->mNumVertices;
	_outMesh->NumFaces = _aiMesh->mNumFaces;

	_outMesh->Faces = new Engine::FACE[_outMesh->NumFaces];
	ZeroMemory(_outMesh->Faces, sizeof(Engine::FACE) * _outMesh->NumFaces);

	for (_uint i = 0; i < _aiMesh->mNumFaces; ++i)
	{
		_outMesh->Faces[i].NumIndices = _aiMesh->mFaces[i].mNumIndices;

		_outMesh->Faces[i].Indices = new _uint[_outMesh->Faces[i].NumIndices];
		ZeroMemory(_outMesh->Faces[i].Indices, sizeof(_uint) * _outMesh->Faces[i].NumIndices);

		for (_uint j = 0; j < _outMesh->Faces[i].NumIndices; ++j)
		{
			_outMesh->Faces[i].Indices[j] = _aiMesh->mFaces[i].mIndices[j];
		}
	}

	_outMesh->Positions = new _float3[_aiMesh->mNumVertices];
	ZeroMemory(_outMesh->Positions, sizeof(_float3) * _aiMesh->mNumVertices);

	_outMesh->Normals = new _float3[_aiMesh->mNumVertices];
	ZeroMemory(_outMesh->Normals, sizeof(_float3) * _aiMesh->mNumVertices);

	_outMesh->TexCoords = new _float2[_aiMesh->mNumVertices];
	ZeroMemory(_outMesh->TexCoords, sizeof(_float2) * _aiMesh->mNumVertices);

	_outMesh->Tangents = new _float3[_aiMesh->mNumVertices];
	ZeroMemory(_outMesh->Tangents, sizeof(_float3) * _aiMesh->mNumVertices);

	for (_uint i = 0; i < _aiMesh->mNumVertices; i++)
	{
		memcpy(&_outMesh->Positions[i], &_aiMesh->mVertices[i], sizeof _float3);
		memcpy(&_outMesh->Normals[i], &_aiMesh->mNormals[i], sizeof _float3);
		memcpy(&_outMesh->TexCoords[i], &_aiMesh->mTextureCoords[0][i], sizeof _float2);
		memcpy(&_outMesh->Tangents[i], &_aiMesh->mTangents[i], sizeof _float3);
	}

	_outMesh->NumBones = _aiMesh->mNumBones;

	_outMesh->Bones = new Engine::BONE[_aiMesh->mNumBones];
	ZeroMemory(_outMesh->Bones, sizeof(Engine::BONE) * _aiMesh->mNumBones);

	for (_uint i = 0; i < _aiMesh->mNumBones; i++)
	{
		aiBone* aiBone = _aiMesh->mBones[i];

		Engine::BONE	bone;
		ZeroMemory(&bone, sizeof(Engine::BONE));

		_tchar BoneName[256] = TEXT("");
		CharToWChar(aiBone->mName.data, BoneName);
		lstrcpy(bone.Name, BoneName);

		_float4x4 TransposeMatrix;
		memcpy(&TransposeMatrix, &aiBone->mOffsetMatrix, sizeof(_float4x4));
		XMStoreFloat4x4(&TransposeMatrix, XMMatrixTranspose(XMLoadFloat4x4(&TransposeMatrix)));
		memcpy(&bone.OffsetMatrix, &TransposeMatrix, sizeof _float4x4);

		bone.NumWeights = aiBone->mNumWeights;

		bone.Weights = new Engine::WEIGHT[aiBone->mNumWeights];
		ZeroMemory(&bone.Weights, sizeof(Engine::WEIGHT) * aiBone->mNumWeights);

		for (_uint j = 0; j < aiBone->mNumWeights; j++)
		{
			aiVertexWeight	aiVertexWeight = aiBone->mWeights[j];

			Engine::WEIGHT weight;
			ZeroMemory(&weight, sizeof(Engine::WEIGHT));

			weight.VertexId = aiVertexWeight.mVertexId;
			weight.Weight = aiVertexWeight.mWeight;

			bone.Weights[j] = weight;
		}

		_outMesh->Bones[i] = bone;
	}

	return S_OK;
}

HRESULT ASSIMP::AIModel::ConvertMaterials(ModelType _modelType, const _char* _modelFilePath)
{
	return S_OK;
}

HRESULT ASSIMP::AIModel::ConvertAnimations()
{
	return E_NOTIMPL;
}

HRESULT ASSIMP::AIModel::WriteFile(ModelType _modelType, const _tchar* _fileName)
{
	return E_NOTIMPL;
}


std::shared_ptr<ASSIMP::AIModel> ASSIMP::AIModel::Create(ModelType _modelType, const std::string& _modelFilePath, _fmatrix _pivotMatrix)
{
	auto instance = std::make_shared<ASSIMP::AIModel>();
	FAILED_CHECK_RETURN_MSG(instance->Initialize(_modelType, _modelFilePath, _pivotMatrix), nullptr, TEXT("Failed"));
	return instance;
}
