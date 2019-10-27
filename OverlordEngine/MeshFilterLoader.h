#pragma once
#include "ContentLoader.h"
#include "MeshFilter.h"

class MeshFilterLoader : public ContentLoader<MeshFilter>
{
	enum class MeshDataTypeOVM
	{
		END = 0,
		HEADER = 1,
		POSITIONS = 2,
		INDICES = 3,
		NORMALS = 4,
		BINORMALS = 5,
		TANGENTS = 6,
		COLORS = 7,
		TEXCOORDS = 8,
		BLENDINDICES = 9,
		BLENDWEIGHTS = 10,
		ANIMATIONCLIPS = 11,
		SKELETON = 12
	};

	enum class MeshDataTypeOBJ
	{
		v,
		vt,
		vn,
		vp,
		f,
		o,
		g,
		s,
		mtllib,
		usemtl
	};
public:
	MeshFilterLoader(const MeshFilterLoader& other) = delete;
	MeshFilterLoader(MeshFilterLoader&& other) noexcept = delete;
	MeshFilterLoader& operator=(const MeshFilterLoader& other) = delete;
	MeshFilterLoader& operator=(MeshFilterLoader&& other) noexcept = delete;
	MeshFilterLoader() = default;
	virtual ~MeshFilterLoader() = default;

protected:
	MeshFilter* LoadContent(const std::wstring& assetFile) override;
	void Destroy(MeshFilter* objToDestroy) override;
	MeshFilter* OVMLoader(const std::wstring& assetFile);
	MeshDataTypeOBJ GetOBJType(std::string type);
	MeshFilter* OBJLoader(const std::wstring& assetFile);
};
