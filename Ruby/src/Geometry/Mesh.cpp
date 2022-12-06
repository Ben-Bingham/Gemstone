#include "Mesh.h"

namespace Ruby {
	Vertex::Vertex(const Malachite::Vector3f& positionData, const Malachite::Vector3f& normalData, const Malachite::Vector2f& textureCoordinateData)
		: position(positionData), normal(normalData), textureCoordinate(textureCoordinateData) {
		
	}

	Vertex::Vertex(const float& posX, const float& posY, const float& posZ, const float& normX, const float& normY, const float& normZ, const float& texCordX, const float& texCordY)
		: position(posX, posY, posZ), normal(normX, normY, normZ), textureCoordinate(texCordX, texCordY) {

	}

	Mesh::Mesh(const Shape shape)
		: m_Vertices(getVerticesFromShape(shape))
		, m_Indices(getIndicesFromShape(shape)) {
		m_VertexAttributes.bind();

		m_VertexBuffer.bind();
		m_VertexBuffer.setData(*(std::vector<float>*)(void*)&m_Vertices);

		m_IndexBuffer.bind();
		m_IndexBuffer.setData(m_Indices);

		m_VertexAttributes.configure();
	}

	Mesh::Mesh() {
		m_VertexAttributes.bind();

		m_VertexBuffer.bind();
		m_VertexBuffer.setNoData();

		m_IndexBuffer.bind();
		m_IndexBuffer.setNoData();

		m_VertexAttributes.configure();
	}

	void Mesh::bind() const {
		m_VertexAttributes.bind();
	}

	Mesh::DrawMode Mesh::getDrawMode() const {
		return m_DrawMode;
	}

	void Mesh::setDrawMode(const DrawMode drawMode) {
		m_DrawMode = drawMode;
	}

	size_t Mesh::getIndexCount() const {
		return m_IndexBuffer.getElementCount();
	}

	Vertices Mesh::getVertices() const {
		return m_Vertices;
	}

	Indices Mesh::getIndices() const {
		return m_Indices;
	}

	Vertices Mesh::getVerticesFromShape(const Shape shape) {
		switch (shape) {
		case Shape::CUBE:
			return ShapeData::getCubeVertices();
		case Shape::SPHERE:
			return ShapeData::getSphereVertices(36, 18);
		case Shape::PLANE:
			return ShapeData::getPlaneVertices();
		}
		LOG("Enum Not Recognized", Lazuli::LogLevel::ERROR);
		return {};
	}

	Indices Mesh::getIndicesFromShape(const Shape shape) {
		switch (shape) {
		case Shape::CUBE:
			return ShapeData::getCubeIndices();
		case Shape::SPHERE:
			return ShapeData::getSphereIndices(36, 18);
		case Shape::PLANE:
			return ShapeData::getPlaneIndices();
		}
		LOG("Enum Not Recognized", Lazuli::LogLevel::ERROR);
		return {};
	}

	void Mesh::edit(const Vertices& newVertices, const unsigned offset) {
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

	void Mesh::edit(const Indices& newIndices, const unsigned offset) {
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

	void Mesh::edit(const Vertices& newVertices) {
		edit(newVertices, 0);
	}

	void Mesh::edit(const Indices& newIndices) {
		edit(newIndices, 0);
	}

	void Mesh::edit(const Vertices& newVertices, const Indices& newIndices) {
		edit(newVertices);
		edit(newIndices);
	}
}