#include "DebugRenderable.h"

namespace Ruby {
	DebugRenderable::DebugRenderable(const std::vector<float>& verticies, Colour Colour)
		: SolidRenderable(verticies, generateIndicies((unsigned int)verticies.size()), Colour) {

	}

	void DebugRenderable::render() const {
		m_VAO.bind();
		ShaderProgram::upload("model", model);
		ShaderProgram::upload("objectColour", colour.toVec3());
		glDrawElements(GL_LINES, m_EBO.getNumberOfIndices(), GL_UNSIGNED_INT, 0);
	}

	std::vector<unsigned int> DebugRenderable::generateIndicies(unsigned int numberOfVerticies) {
		std::vector<unsigned int> indicies;
		for (unsigned int i = 0; i < numberOfVerticies; i++) {
			indicies.push_back(i);
		}

		return indicies;
	}

	DebugLine::DebugLine(const Malachite::Vector3f& point1, const Malachite::Vector3f& point2, Colour colour)
		: DebugRenderable(generateVerticies(point1, point2), colour) {

	}

	std::vector<float> DebugLine::generateVerticies(const Malachite::Vector3f& point1, const Malachite::Vector3f& point2) {
		std::vector<float> verticies;
		verticies.push_back(point1.x);
		verticies.push_back(point1.y);
		verticies.push_back(point1.z);

		verticies.push_back(point2.x);
		verticies.push_back(point2.y);
		verticies.push_back(point2.z);

		return verticies;
	}
}