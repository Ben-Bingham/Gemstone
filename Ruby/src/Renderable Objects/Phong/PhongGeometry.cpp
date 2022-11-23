#include "PhongGeometry.h"

namespace Ruby {
	PhongGeometry::PhongGeometry(std::unique_ptr<GeometryData> geometryObject, PhongMaterial& mat) 
		: PhongRenderable(geometryObject->getVerticies(true, true), geometryObject->getIndicies(), mat) {

	}

	void PhongGeometry::render() const {
		m_VAO.bind();
		ShaderProgram::upload("model", model);
		ShaderProgram::upload("material", 0, *material);
		glDrawElements(GL_TRIANGLES, m_NumberOfIndices, GL_UNSIGNED_INT, 0);
	}
}