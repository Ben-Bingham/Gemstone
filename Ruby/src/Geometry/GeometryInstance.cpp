#include "GeometryInstance.h"

namespace Ruby {
	GeometryInstance::GeometryInstance(Ptr<GeometryData> geometryData, const VertexShader::LayoutData& layoutData)
		: m_GeometryData(std::move(geometryData)), m_LayoutData(layoutData) {

		m_VAO.bind();

		m_VertexBuffer.bind();
		const std::vector<float> vertices = m_GeometryData->getVertices(m_LayoutData);
		if (!vertices.empty()) {
			m_VertexBuffer.setData(vertices);
		}
		else {
			m_VertexBuffer.setNoData();
		}

		m_IndexBuffer.bind();
		const std::vector<unsigned int> indices = m_GeometryData->getIndices();
		if (!indices.empty()) {
			m_IndexBuffer.setData(indices);
		}
		else {
			m_IndexBuffer.setNoData();
		}

		m_VAO.configureForLayout(m_LayoutData);
	}

	void GeometryInstance::use() const {
		m_VAO.bind();
	}

	VertexShader::LayoutData GeometryInstance::getDataLayout() const {
		return m_LayoutData;
	}

	GeometryData& GeometryInstance::getGeometryData() const {
		return *m_GeometryData;
	}

	size_t GeometryInstance::getIndexCount() const {
		return m_IndexBuffer.getElementCount();
	}

	void GeometryInstance::setData(const Ptr<GeometryData>& geometryData) {
		m_GeometryData = geometryData;

		const std::vector<float> vertices = m_GeometryData->getVertices(m_LayoutData);
		const std::vector<unsigned int> indices = m_GeometryData->getIndices();

		if (vertices.size() < m_VertexBuffer.getElementCount()) {
			m_VertexBuffer.setData(vertices);
		}
		else {
			m_VertexBuffer = VertexBuffer{ vertices };
		}

		if (indices.size() < m_IndexBuffer.getElementCount()) {
			m_IndexBuffer.setData(indices);
		}
		else {
			m_IndexBuffer = IndexBuffer{ indices };
		}
	}
}