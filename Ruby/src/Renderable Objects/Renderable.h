#pragma once

#include "Shaders/ShaderProgram.h"

#include "OpenGL objects/VertexAttributeObject.h"
#include "OpenGL objects/VertexBufferObject.h"
#include "OpenGL objects/ElementBufferObject.h"

namespace Ruby {
	class Renderable {
	public:
		Renderable(const std::vector<float>& verticies, const std::vector<unsigned int>& indicies, const std::vector<Attribute>& attributes) {
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

		// The assumption is made that a shader program is bound prior to this being called
		virtual void render() const {
			VAO.bind();
			glDrawElements(GL_TRIANGLES, numberOfIndicies, GL_UNSIGNED_INT, 0);
		}

	protected:
		VertexAttributeObject VAO{ };
		VertexBufferObject VBO{ };
		ElementBufferObject EBO{ };

		unsigned int numberOfIndicies;
	};
}