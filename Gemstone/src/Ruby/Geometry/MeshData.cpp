#include "MeshData.h"

namespace Ruby {
	Vertex::Vertex(const Malachite::Vector3f& positionData, const Malachite::Vector3f& normalData, const Malachite::Vector2f& textureCoordinateData)
		: position(positionData), normal(normalData), textureCoordinate(textureCoordinateData) {
		
	}

	Vertex::Vertex(const float& posX, const float& posY, const float& posZ, const float& normX, const float& normY, const float& normZ, const float& texCordX, const float& texCordY)
		: position(posX, posY, posZ), normal(normX, normY, normZ), textureCoordinate(texCordX, texCordY) {

	}

	MeshData::MeshData(const Celestite::Ptr<Shape>& shape)
		: m_Vertices(shape->GetVertices())
		, m_Indices(shape->GetIndices())
	{
		m_VertexAttributes.bind();

		m_VertexBuffer.bind();
		m_VertexBuffer.setData(*(std::vector<float>*)(void*)&m_Vertices);

		m_IndexBuffer.bind();
		m_IndexBuffer.setData(m_Indices);

		m_VertexAttributes.configure();
	}

	MeshData::MeshData() {
		m_VertexAttributes.bind();

		m_VertexBuffer.bind();
		m_VertexBuffer.setNoData();

		m_IndexBuffer.bind();
		m_IndexBuffer.setNoData();

		m_VertexAttributes.configure();
	}

	void MeshData::bind() const {
		m_VertexAttributes.bind();
	}

	void MeshData::ForceBind() const {
		m_VertexAttributes.ForceBind();
	}

	MeshData::DrawMode MeshData::getDrawMode() const {
		return m_DrawMode;
	}

	void MeshData::setDrawMode(const DrawMode drawMode) {
		m_DrawMode = drawMode;
	}

	size_t MeshData::getIndexCount() const {
		return m_IndexBuffer.getElementCount();
	}

	Vertices MeshData::getVertices() const {
		return m_Vertices;
	}

	Indices MeshData::getIndices() const {
		return m_Indices;
	}

	Celestite::Ptr<Shape> MeshData::GetShape() {
		return m_Shape;
	}

	void MeshData::edit(const Vertices& newVertices, const unsigned offset) {
		if (newVertices.size() + offset < m_Vertices.size()) {
			memcpy(m_Vertices.data() + offset, newVertices.data(), newVertices.size() * sizeof(Vertex));
		}
		else {
			m_Vertices = newVertices;
		}

		if (newVertices.size() + offset < m_VertexBuffer.getElementCount() / 5) {
			m_VertexAttributes.bind();
			m_VertexBuffer.bind();

			m_VertexBuffer.setSubData(*(std::vector<float>*)(void*)&newVertices, offset);
		}
		else {
			m_VertexBuffer = VertexBuffer{ *(std::vector<float>*)(void*)&newVertices };
		}
	}

	void MeshData::edit(const Indices& newIndices, const unsigned offset) {
		if (newIndices.size() + offset < m_Indices.size()) {
			memcpy(m_Indices.data() + offset, newIndices.data(), newIndices.size() * sizeof(Index));
		}
		else {
			m_Indices = newIndices;
		}
		
		if (newIndices.size() + offset < m_IndexBuffer.getElementCount()) {
			m_VertexAttributes.bind();
			m_IndexBuffer.bind();
			m_IndexBuffer.setSubData(*(std::vector<unsigned int>*)(void*)&newIndices, offset);
		}
		else {
			m_IndexBuffer = IndexBuffer{ *(std::vector<unsigned int>*)(void*) & newIndices };
		}
	}

	void MeshData::edit(const Vertices& newVertices) {
		edit(newVertices, 0);
	}

	void MeshData::edit(const Indices& newIndices) {
		edit(newIndices, 0);
	}

	void MeshData::edit(const Vertices& newVertices, const Indices& newIndices) {
		edit(newVertices);
		edit(newIndices);
	}
}