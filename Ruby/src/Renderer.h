#pragma once

#include <GL/glew.h>

#include "Log.h"
#include "Shaders/VertexShader.h"
#include "Shaders/FragmentShader.h"
#include "Shaders/ShaderProgram.h"

#include "OpenGL objects/VertexAttributeObject.h"
#include "OpenGL objects/VertexBufferObject.h"
#include "OpenGL objects/ElementBufferObject.h"

#include "RenderableObject.h"

namespace Ruby {
	class Renderer {
	public:
		Renderer() : renderable(initRenderable()) {}

		void render() {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            renderable.render();
            
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}

        RenderableObject initRenderable() {
            std::vector<float> verticies{
                 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   // top right
                 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   // bottom right
                -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 0.0f,   // bottom left
                -0.5f,  0.5f, 0.0f,   0.0f, 0.0f, 1.0f    // top left 
            };

            std::vector<unsigned int> indices{
                0, 1, 3,  // first Triangle
                1, 2, 3   // second Triangle
            };

            FragmentShader fragmentShader{ TextFile{"..\\Ruby\\assets\\shaders\\Default.frag"} };
            VertexShader vertexShader{ TextFile{ "..\\Ruby\\assets\\shaders\\Default.vert" } };
            std::shared_ptr<ShaderProgram> shaderProgram = std::make_shared<ShaderProgram>(vertexShader, fragmentShader);

            std::vector<Attribute> attributes;
            attributes.push_back(3);
            attributes.push_back(3);

            return RenderableObject{ shaderProgram, verticies, indices, attributes };
        }
        RenderableObject renderable;
	};
}