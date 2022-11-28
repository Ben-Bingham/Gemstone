#include "Renderable.h"

namespace Ruby {
	Renderable::Renderable(GeometryData& geometry, Material& material) 
		: m_Material(&material), m_GeometryData(&geometry) {

		m_VAO.bind();

		m_VBO.bind();
		m_VBO.setData(m_GeometryData->getVertices(material.getLayout()));

		m_EBO.bind();
		m_EBO.setData(m_GeometryData->getIndices());

		m_VAO.configureForLayout(material.getLayout());
	}

	Malachite::Matrix4f& Renderable::getModelMatrix() {
		return m_ModelMatrix;
	}

	void Renderable::render(const Malachite::Matrix4f& view, const Malachite::Matrix4f& projection) const {
		m_VAO.bind();

		m_Material->use(m_ModelMatrix, view, projection);
		glDrawElements(GL_TRIANGLES, (GLsizei)m_EBO.getNumberOfIndices(), GL_UNSIGNED_INT, 0);
		m_Material->end();
	}
}