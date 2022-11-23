#pragma once

#include "Renderable.h"
#include "OpenGL objects/Cubemap.h"

namespace Ruby {
	class SkyBox : public Renderable {
	public:
		SkyBox(std::vector<Image>& faces)
			: Renderable(verticies, indices, std::vector<Attribute>{ 3 }), cubemap(faces) {

		}

		void render() const override {
			m_VAO.bind();
			ShaderProgram::upload("skybox", 0, cubemap);
			glDrawElements(GL_TRIANGLES, m_EBO.getNumberOfIndices(), GL_UNSIGNED_INT, 0);
		}

	private:
		Cubemap cubemap;

		static const std::vector<float> verticies;
		static const std::vector<unsigned int> indices;
	};
}