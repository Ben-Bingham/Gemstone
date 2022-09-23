#pragma once

#include "Renderable Objects/Renderable.h"

namespace Ruby {
	class PhongRenderable : public Renderable {
	public:
		PhongRenderable(const std::vector<float>& verticies, const std::vector<unsigned int>& indicies, PhongMaterial& mat)
			: Renderable(verticies, indicies, std::vector<Attribute>{ 3, 3, 2 }), material(std::move(mat)) {

		}

		void render() const override {
			VAO.bind();
			ShaderProgram::upload("model", model);
			ShaderProgram::upload("material", 0, material);
			glDrawElements(GL_TRIANGLES, numberOfIndicies, GL_UNSIGNED_INT, 0);
		}

		Malachite::Matrix4f model{ 1.0f };
		PhongMaterial material{ };
	};
	
}