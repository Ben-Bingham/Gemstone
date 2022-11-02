#include "PhongGeometry.h"

namespace Ruby {
	PhongGeometry::PhongGeometry(std::unique_ptr<GeometryObject> geometryObject, PhongMaterial& mat) 
		: PhongRenderable(geometryObject->getVerticies(true, true), geometryObject->getIndicies(), mat) {

	}

	void PhongGeometry::render() const {
		VAO.bind();
		ShaderProgram::upload("model", model);
		ShaderProgram::upload("material", 0, *material);
		glDrawElements(GL_TRIANGLES, numberOfIndicies, GL_UNSIGNED_INT, 0);
	}
}