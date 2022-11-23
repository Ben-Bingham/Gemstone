#include "SolidRenderable.h"

namespace Ruby {
	SolidRenderable::SolidRenderable(const std::vector<float>& vertices, const std::vector<unsigned int>& indices, const Colour& colour)
		: Renderable(vertices, indices, std::vector<Attribute>{ 3 }), colour(colour) {

	}

	void SolidRenderable::render() const {
		m_VAO.bind();
		ShaderProgram::upload("model", model);
		ShaderProgram::upload("objectColour", colour.toVec3());
		glDrawElements(GL_TRIANGLES, (GLsizei)m_EBO.getNumberOfIndices(), GL_UNSIGNED_INT, 0);
	}
}