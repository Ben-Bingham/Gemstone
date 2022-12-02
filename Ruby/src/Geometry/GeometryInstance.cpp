#include "GeometryInstance.h"

namespace Ruby {
	GeometryInstance::GeometryInstance(GeometryData& geometryData, const VertexShader::LayoutData& layoutData) 
		: m_GeoemetryData(&geometryData) {

		m_VAO.bind();

		m_VertexBuffer.bind();
		m_VertexBuffer.setData(m_GeoemetryData->getVertices(layoutData));

		m_IndexBuffer.bind();
		m_IndexBuffer.setData(m_GeoemetryData->getIndices());

		m_VAO.configureForLayout(layoutData);
	}

	void GeometryInstance::use() {
		m_VAO.bind();
	}
}