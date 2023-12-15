#include "pch.h"
#include "Rendering/Components/Mesh.h"
#include "Rendering/OpenGlContext.h"
#include "Rendering/Geometry/Shapes.h"

namespace Gem {
	//Mesh::Mesh(const Shape& shape)
	//	: Mesh(shape.Vertices(), shape.Indices()) {
	//}

	//Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<Index>& indices)
	//	: Mesh(ReorganizeVertexData(vertices), indices) {
	//}

	//Mesh::Mesh(const std::vector<float>& vertices, const std::vector<unsigned int>& indices)
	//	: m_InternalMesh(CreatePtr<InternalMesh>(vertices, indices)) { }

	/*std::vector<float> GetRawMesh::ReorganizeVertexData(const std::vector<Vertex>& vertices) {
		std::vector<float> reorganizedVertexData;

		reorganizedVertexData.resize(vertices.size() * ELEMENTS_IN_VERTEX);

		std::memcpy(reorganizedVertexData.data(), vertices.data(), reorganizedVertexData.size() * sizeof(float));
	
		return reorganizedVertexData;
	}*/
}