#pragma once

#include "Shaders/ShaderProgram.h"

#include "OpenGL objects/VertexAttributeObject.h"
#include "OpenGL objects/VertexBufferObject.h"
#include "OpenGL objects/ElementBufferObject.h"

namespace Ruby {
	class RenderableObject {
	public:
		RenderableObject(std::vector<float>& verticies, std::vector<unsigned int>& indicies, std::vector<Attribute> attributes) {
			VAO.bind();

			VBO.bind();
			VBO.setData(verticies);

			EBO.bind();
			EBO.setData(indicies);
			numberOfIndicies = (unsigned int)indicies.size();

			for (Attribute attribute : attributes) {
				VAO.addAttribute(attribute);
			}

			VAO.compileAttributes();
		}

		void render() const {
			glDrawElements(GL_TRIANGLES, numberOfIndicies, GL_UNSIGNED_INT, 0);
		}

		void dispose() {
			VAO.dispose();
			VBO.dispose();
			EBO.dispose();
		}

	private:
		VertexAttributeObject VAO{ };
		VertexBufferObject VBO{ };
		ElementBufferObject EBO{ };

		unsigned int numberOfIndicies;
	};
}