#include "PhongRenderable.h"

namespace Ruby {
	PhongRenderable::PhongRenderable(const std::vector<float>& vertices, const std::vector<unsigned int>& indices, PhongMaterial& mat)
		: Renderable(vertices, indices, std::vector<Attribute>{ 3, 3, 2 }), material(&mat) {

	}

	void PhongRenderable::render() const {
		m_VAO.bind();
		ShaderProgram::upload("model", model);
		ShaderProgram::upload("material", 0, *material);
		glDrawElements(GL_TRIANGLES, (GLsizei)m_NumberOfIndices, GL_UNSIGNED_INT, 0);
	}
}