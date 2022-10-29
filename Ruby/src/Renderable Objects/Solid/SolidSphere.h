#pragma once

#include "SolidRenderable.h"

namespace Ruby {
	class SolidSphere : public SolidRenderable {
	public:
		SolidSphere(SolidMaterial& mat, unsigned int numberOfSections = 36u, unsigned int numberOfStacks = 18u);

		void render() const override {
			VAO.bind();
			ShaderProgram::upload("model", model);
			ShaderProgram::upload("objectColour", material.colour);
			glDrawElements(GL_TRIANGLES, numberOfIndicies, GL_UNSIGNED_INT, 0);
		}

	protected:
		unsigned int numberOfSections;
		unsigned int numberOfStacks;

	private:
		SolidRenderable solidRenderableInit(SolidMaterial& mat, unsigned int numberOfSections, unsigned int numberOfStacks);
	};
}