#include "GeometryInstance.h"

namespace Ruby {
	GeometryInstance::GeometryInstance(Ptr<GeometryData> geometryData, const VertexShader::LayoutData& layoutData)
		: m_GeometryData(std::move(geometryData)), m_LayoutData(layoutData) {

		m_VAO.bind();

		m_VertexBuffer.bind();
		m_VertexBuffer.setData(m_GeometryData->getVertices(m_LayoutData));

		m_IndexBuffer.bind();
		m_IndexBuffer.setData(m_GeometryData->getIndices());

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
}