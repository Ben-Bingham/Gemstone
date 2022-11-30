#include "Renderable.h"

namespace Ruby {
	Renderable::Renderable(const GeometryData& geometry, Material& material)
		: m_Material(&material)/*, m_GeometryData(&geometry)*/ {
		m_VAO.bind();

		m_VBO.bind();
		m_VBO.setData(geometry.getVertices(material.getLayout()));

		m_EBO.bind();
		m_EBO.setData(geometry.getIndices());

		m_VAO.configureForLayout(material.getLayout());
		//m_VAO.bind();

		//m_VBO.bind();
		//std::vector<float> vertexData = geometry.getVertices(material.getLayout());
		//if (vertexData.size() > 0) {
		//	m_VBO.setData(vertexData);
		//}
		//else {
		//	m_VBO.setNoData(512 * sizeof(float) * 3);
		//}

		//m_EBO.bind();
		//std::vector<unsigned int> indexData = geometry.getIndices();
		//if (indexData.size() > 0) {
		//	m_EBO.setData(geometry.getIndices());
		//}
		//else {
		//	m_EBO.setNoData(512 * sizeof(unsigned int));
		//}

		//m_VAO.configureForLayout(material.getLayout());
	}

	Malachite::Matrix4f& Renderable::getModelMatrix() {
		return m_ModelMatrix;
	}

	void Renderable::setMaterial(Material& material) {
		m_Material = &material;
	}

	void Renderable::setGeometryData(const GeometryData& geometry) {
		m_VAO.bind();

		m_VBO.bind();
		std::vector<float> newVertexData = geometry.getVertices(m_Material->getLayout());
		std::vector<unsigned int> newIndexData = geometry.getIndices();

		if (newVertexData.size() > 0 && newIndexData.size() > 0 && newIndexData.size() < m_EBO.getNumberOfIndices()) {
			m_VBO.setPartialData(newVertexData, 0);
			m_EBO.setPartialData(newIndexData, 0);
		}
		else {
			// TODO
		}
	}

	void Renderable::render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) const {
		m_VAO.bind();

		m_Material->use(m_ModelMatrix, view, projection);
		glDrawElements(GL_TRIANGLES, (GLsizei)m_EBO.getNumberOfIndices(), GL_UNSIGNED_INT, 0);
		m_Material->end();
	}
}