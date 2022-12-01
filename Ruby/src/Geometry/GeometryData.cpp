#include "GeometryData.h"

namespace Ruby {
	GeometryData::GeometryData() {
		m_VAO.bind();

		m_VertexBuffer.bind();
		m_VertexBuffer.setData(nullptr);
		m_EBO.bind();
	}
}