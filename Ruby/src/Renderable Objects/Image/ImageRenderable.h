#pragma once

#include "Renderable Objects/Renderable.h"

namespace Ruby {
	class ImageRenderable : public Renderable {
	public:
		ImageRenderable(const std::vector<float>& verticies, const std::vector<unsigned int>& indicies, ImageMaterial& mat)
			: Renderable(verticies, indicies, std::vector<Attribute>{ 3, 2 }), material(&mat) {

		}

		void render() const override {
			VAO.bind();
			ShaderProgram::upload("model", model);
			ShaderProgram::upload("image", 0, material->texture);
			glDrawElements(GL_TRIANGLES, numberOfIndicies, GL_UNSIGNED_INT, 0);
		}

		Malachite::Matrix4f model{ 1.0f };
		ImageMaterial* material{ };
	};
}