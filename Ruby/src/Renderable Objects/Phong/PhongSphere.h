#pragma once

#include "PhongRenderable.h"

namespace Ruby {
	class PhongSphere : public PhongRenderable {
	public:
		PhongSphere(PhongMaterial& mat, unsigned int numberOfSections = 36u, unsigned int numberOfStacks = 18u);

		void render() const override {
			VAO.bind();
			ShaderProgram::upload("model", model);
			ShaderProgram::upload("material", 0, *material);
			glDrawElements(GL_TRIANGLES, numberOfIndicies, GL_UNSIGNED_INT, 0);
		}


	protected:
		unsigned int numberOfSections;
		unsigned int numberOfStacks;

	private:
		PhongRenderable phongRenderableInit(PhongMaterial& mat, unsigned int numberOfSections, unsigned int numberOfStacks);
	};
}