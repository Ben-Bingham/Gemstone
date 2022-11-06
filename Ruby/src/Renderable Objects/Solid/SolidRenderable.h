#pragma once

#include "Colour.h"
#include "Renderable Objects/Renderable.h"

namespace Ruby {
	class SolidRenderable : public Renderable {
	public:
		SolidRenderable(const std::vector<float>& verticies, const std::vector<unsigned int>& indicies, const Colour Colour)
			: Renderable(verticies, indicies, std::vector<Attribute>{ 3 }), colour(Colour) {

		}

		void render() const override {
			VAO.bind();
			ShaderProgram::upload("model", model);
			ShaderProgram::upload("objectColour", colour.toVec3());
			glDrawElements(GL_TRIANGLES, numberOfIndicies, GL_UNSIGNED_INT, 0);
		}

		Malachite::Matrix4f model{ 1.0f };
		Colour colour;
	};
}