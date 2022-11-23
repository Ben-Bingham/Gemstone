#include "Renderable.h"

namespace Ruby {
	Renderable::Renderable(const std::vector<float>& vertices, const std::vector<unsigned int>& indices, const std::vector<Attribute>& attributes) {
		m_VAO.bind();

		m_VBO.bind();
		m_VBO.setData(vertices);

		m_EBO.bind();
		m_EBO.setData(indices);
		m_NumberOfIndices = (unsigned int)indices.size();

		for (const Attribute attribute : attributes) {
			m_VAO.addAttribute(attribute);
		}

		m_VAO.compileAttributes();
	}

	Renderable::Renderable(const GeometryDataPtr& geometry, const MaterialPtr& material) 
		: m_Material(material), m_GeometryData(geometry) {

	}

	void Renderable::render() const { //TODO split this into header and cpp file for all renderables
		m_VAO.bind();

		glDrawElements(GL_TRIANGLES, (GLsizei)m_NumberOfIndices, GL_UNSIGNED_INT, 0);
	}
}