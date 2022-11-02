#include "SolidGeometry.h"

namespace Ruby {
	SolidGeometry::SolidGeometry(std::unique_ptr<GeometryObject> geometryObject, SolidMaterial& mat) 
		: SolidRenderable(geometryObject->getVerticies(false, false), geometryObject->getIndicies(), mat) {

	}

	void SolidGeometry::render() const {
		VAO.bind();
		ShaderProgram::upload("model", model);
		ShaderProgram::upload("objectColour", material.colour);
		glDrawElements(GL_TRIANGLES, numberOfIndicies, GL_UNSIGNED_INT, 0);
	}

}