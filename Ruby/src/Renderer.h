#pragma once

#include <GL/glew.h>

#include "Log.h"
#include "Shaders/VertexShader.h"
#include "Shaders/FragmentShader.h"
#include "Shaders/ShaderProgram.h"

#include "OpenGL objects/VertexAttributeObject.h"
#include "OpenGL objects/VertexBufferObject.h"
#include "OpenGL objects/ElementBufferObject.h"

namespace Ruby {
	class Renderer {
	public:
		Renderer() : shaderProgram(initProgram()) {
            std::vector<float> verticies{
                 0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 1.0f, // top right
                 0.5f, -0.5f, 0.0f,  1.0f, 1.0f, 1.0f, // bottom right
                -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 0.0f, // bottom left
                -0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 0.0f  // top left 
            };

            std::vector<unsigned int> indices{
                0, 1, 3,  // first Triangle
                1, 2, 3   // second Triangle
            };

            VAO.bind();

            VertexBufferObject VBO{ verticies };
            ElementBufferObject EBO{ indices };

            VBO.bind();

            EBO.bind();

            VAO.enableAttributePointer(3, AttributeType::FLOAT, 6 * sizeof(float));
            VAO.enableAttributePointer(3, AttributeType::FLOAT, 6 * sizeof(float));
		}

		void render() {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            shaderProgram.use();
            VAO.bind();
            
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}

        ShaderProgram initProgram() {
            FragmentShader fragmentShader{ TextFile{"..\\Ruby\\assets\\shaders\\Default.frag"} };
            VertexShader vertexShader{ TextFile{ "..\\Ruby\\assets\\shaders\\Default.vert" } };

            return ShaderProgram{ vertexShader, fragmentShader };
        }

        ShaderProgram shaderProgram;
        VertexAttributeObject VAO;
	};
}