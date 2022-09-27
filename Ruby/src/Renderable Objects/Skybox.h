#pragma once

#include "Renderable.h"
#include "OpenGL objects/Cubemap.h"

namespace Ruby {
	class Skybox : public Renderable {
	public:
		Skybox(std::vector<Image>& faces)
			: Renderable(verticies, indices, std::vector<Attribute>{ 3 }), cubemap(faces) {

		}

		void render() const override {
			VAO.bind();
			ShaderProgram::upload("skybox", 0, cubemap);
			glDrawElements(GL_TRIANGLES, numberOfIndicies, GL_UNSIGNED_INT, 0);
		}

	private:
		Cubemap cubemap;

		static const std::vector<float> verticies;
		static const std::vector<unsigned int> indices;
	};
}