#pragma once
#include "RawMesh.h"
#include "Rendering/OpenGl Objects/GlBuffer.h"
#include "Rendering/OpenGl Objects/VertexAttributeObject.h"

namespace Gem {
	// Contains information required by openGl for rendering
	class MeshData {
	public:
		MeshData(const RawMesh& rawMesh);
		MeshData(const MeshData& other) = delete;
		MeshData(MeshData&& other) noexcept = default;
		MeshData& operator=(const MeshData& other) = delete;
		MeshData& operator=(MeshData&& other) noexcept = default;
		~MeshData() = default;

		VertexAttributeObject vao;
		VertexBuffer vb;
		IndexBuffer ib;
		size_t indexCount;
	};
}