#pragma once

#include "Renderable Objects/Renderable.h"

namespace Ruby {
	class SolidRenderable : public Renderable {
	public:
		SolidRenderable(const std::vector<float>& verticies, const std::vector<unsigned int>& indicies, SolidMaterial& mat)
			: Renderable(verticies, indicies, std::vector<Attribute>{ 3 }), material(std::move(mat)) {

		}

		virtual void render() const {
			VAO.bind();
			ShaderProgram::upload("objectColour", material.colour);
			glDrawElements(GL_TRIANGLES, numberOfIndicies, GL_UNSIGNED_INT, 0);
		}

	protected:
		SolidMaterial material{ };
	};
}