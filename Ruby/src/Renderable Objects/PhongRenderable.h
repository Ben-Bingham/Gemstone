#pragma once

#include "RenderableObject.h"

namespace Ruby {
	class PhongRenderable : public RenderableObject {
	public:
		PhongRenderable(std::vector<float>& verticies, std::vector<unsigned int>& indicies) 
			: RenderableObject(verticies, indicies, std::vector<Attribute>{ 3, 3, 2 }) {

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