#pragma once

#include <GL/glew.h>

#include "Log.h"

#include "Renderable Objects/RenderableObject.h"

namespace Ruby {
	class Renderer {
	public:
		Renderer() 
            : normalShader(shaderInit("..\\Ruby\\assets\\shaders\\Default.vert", "..\\Ruby\\assets\\shaders\\Default.frag", std::vector<Ruby::Attribute>{ 3, 3 })),
              solidShader(shaderInit("..\\Ruby\\assets\\shaders\\Solid.vert", "..\\Ruby\\assets\\shaders\\Solid.frag", std::vector<Ruby::Attribute>{ 3, 3, 2 }))
        {
            glEnable(GL_DEPTH_TEST);
        }

        void prep() {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void render(RenderableObject renderable) {
            renderable.render();
        }

        void finish() {

        }

        void dispose() {
            normalShader.dispose();
            solidShader.dispose();
        }

        ShaderProgram normalShader; // once there are many more shaders they can be moved into a shader Library class
        ShaderProgram solidShader; // once there are many more shaders they can be moved into a shader Library class

    private:
        ShaderProgram shaderInit(const std::string& vertexShaderPath, const std::string& fragmentShaderPath, const std::vector<Attribute>& attributes) {
            return ShaderProgram{ VertexShader{vertexShaderPath}, FragmentShader{fragmentShaderPath}, attributes };
        }
	};
}