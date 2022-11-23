#pragma once

#include "ImageRenderable.h"

namespace Ruby {
	class ImageQuad : public ImageRenderable {
	public:
		ImageQuad(ImageMaterial& mat)
			: ImageRenderable(verticies, indices, mat) {

		}

		void render() const override {
			m_VAO.bind();
			ShaderProgram::upload("model", model);
			ShaderProgram::upload("image", 0, *material->texture);
			glDrawElements(GL_TRIANGLES, m_EBO.getNumberOfIndices(), GL_UNSIGNED_INT, 0);
		}

	private:
		static const std::vector<float> verticies;
		static const std::vector<unsigned int> indices;
	};
}