#pragma once

#include "SolidRenderable.h"

namespace Ruby {
	class SolidCube : public SolidRenderable {
	public:
		SolidCube(SolidMaterial& mat)
			: SolidRenderable(verticies, indices, mat) {

		}

		virtual void render() const {
			VAO.bind();
			ShaderProgram::upload("model", model);
			ShaderProgram::upload("objectColour", material.colour);
			glDrawElements(GL_TRIANGLES, numberOfIndicies, GL_UNSIGNED_INT, 0);
		}

	private:
		static const std::vector<float> verticies;
		static const std::vector<unsigned int> indices;
	};
	
}