#include "ScreenQuad.h"

namespace Ruby {
	ScreenQuad::ScreenQuad(const Texture* texture)
		: Renderable(verticies, indicies, std::vector<Attribute>{3, 2})
		, m_Texture(texture) { }

	void ScreenQuad::render() const {
		VAO.bind();
		ShaderProgram::upload("image", 0, *m_Texture);
		glDrawElements(GL_TRIANGLES, numberOfIndicies, GL_UNSIGNED_INT, nullptr);
	}

	const std::vector<float> ScreenQuad::verticies = {
		-1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
		-1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
		1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
		1.0f, 1.0f, 0.0f, 1.0f, 1.0f
	};

	const std::vector<unsigned int> ScreenQuad::indicies = {
		0, 1, 2,
		0, 2, 3
	};
}