#include "GeometryData.h"

namespace Ruby {
	GeometryData::GeometryData() {
		m_VAO.bind();
		
		m_VertexBuffer.bind();
		m_VertexBuffer.setNoData();

		m_IndexBuffer.bind();
		m_IndexBuffer.setNoData();
	}
}