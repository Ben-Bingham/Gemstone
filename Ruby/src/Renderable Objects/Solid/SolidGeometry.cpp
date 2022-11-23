#include "SolidGeometry.h"

namespace Ruby {
	SolidGeometry::SolidGeometry(std::unique_ptr<GeometryData> geometryObject, const Colour Colour) 
		: SolidRenderable(geometryObject->getVerticies(false, false), geometryObject->getIndicies(), Colour) {

	}

	void SolidGeometry::render() const {
		m_VAO.bind();
		ShaderProgram::upload("model", model);
		ShaderProgram::upload("objectColour", colour.toVec3());
		glDrawElements(GL_TRIANGLES, m_EBO.getNumberOfIndices(), GL_UNSIGNED_INT, 0);
	}

}