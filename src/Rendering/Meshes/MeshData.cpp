#include "Rendering/Meshes/MeshData.h"

namespace Gem {
	MeshData::MeshData(const RawMesh& rawMesh)
		: indexCount(rawMesh.indices.size()) {
		vao.Bind();

		vb.Bind();
		vb.SetAllData(VertexToFloat(rawMesh.vertices));

		ib.Bind();
		ib.SetAllData(rawMesh.indices);

		vao.SetLayout({
			{ OpenGlContext::VECTOR3F, "l_Position" },
			{ OpenGlContext::VECTOR3F, "l_Normal" },
			{ OpenGlContext::VECTOR2F, "l_Uv" }
		});
	}

	void MeshData::Bind() const {
		vao.Bind();
	}
}