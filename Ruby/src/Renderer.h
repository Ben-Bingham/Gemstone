#pragma once

#include <GL/glew.h>

#include "Log.h"

#include "Renderable Objects/Renderable.h"
#include "Renderable Objects/Phong/PhongRenderable.h"
#include "Renderable Objects/Solid/SolidRenderable.h"

namespace Ruby {
	class Renderer {
	public:
		Renderer() 
            : phongShader(shaderInit("..\\Ruby\\assets\\shaders\\Phong.vert", "..\\Ruby\\assets\\shaders\\Phong.frag", std::vector<Ruby::Attribute>{ 3, 3, 2 })),
              solidShader(shaderInit("..\\Ruby\\assets\\shaders\\Solid.vert", "..\\Ruby\\assets\\shaders\\Solid.frag", std::vector<Ruby::Attribute>{ 3 })),
              testShader(shaderInit("..\\Ruby\\assets\\shaders\\test.vert", "..\\Ruby\\assets\\shaders\\test.frag", std::vector<Ruby::Attribute>{ 3, 3, 2 }))
        {
            glEnable(GL_DEPTH_TEST);
        }

        void prep() {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void render(const Renderable& renderable) const {
            renderable.render();
        }

        void end() {

        }

        // Phong rendering
        void normalRenderingPrep() const {

        }

        void normalRender(const PhongRenderable& renderable) const {
            renderable.render();
        }

        void normalRenderingEnd() const {

        }

        // Solid rendering
        void solidRenderingPrep() const {

        }

        void solidRender(const SolidRenderable& renderable) const {
            renderable.render();
        }

        void solidRenderingEnd() const {

        }

        ShaderProgram phongShader; // once there are many more shaders they can be moved into a shader Library class
        ShaderProgram solidShader; // once there are many more shaders they can be moved into a shader Library class
        ShaderProgram testShader;

    private:
        ShaderProgram shaderInit(const std::string& vertexShaderPath, const std::string& fragmentShaderPath, const std::vector<Attribute>& attributes) {
            return ShaderProgram{ VertexShader{vertexShaderPath}, FragmentShader{fragmentShaderPath}, attributes };
        }
	};
}