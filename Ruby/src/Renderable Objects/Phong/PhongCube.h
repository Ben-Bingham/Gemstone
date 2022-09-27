#pragma once

#include "PhongRenderable.h"

namespace Ruby {
	class ShadowPhongCube : public ShadowPhongRenderable {
	public:
		ShadowPhongCube(PhongMaterial& mat)
			: ShadowPhongRenderable(verticies, indices, std::move(mat)) {

		}

		void render() const override {
			VAO.bind();
			ShaderProgram::upload("model", model);
			ShaderProgram::upload("material", 0, *material);
			glDrawElements(GL_TRIANGLES, numberOfIndicies, GL_UNSIGNED_INT, 0);
		}

	private:
		static const std::vector<float> verticies;
		static const std::vector<unsigned int> indices;
	};
}
