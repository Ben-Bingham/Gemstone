#pragma once

#include "Renderable Objects/RenderableObject.h"

namespace Ruby {
	class PhongRenderable : public RenderableObject {
	public:
		PhongRenderable(std::vector<float>& verticies, std::vector<unsigned int>& indicies, PhongMaterial& mat) 
			: RenderableObject(verticies, indicies, std::vector<Attribute>{ 3, 3, 2 }), material(std::move(mat)) {

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