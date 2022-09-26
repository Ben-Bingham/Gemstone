#pragma once

#include <GL/glew.h>

#include "Log.h"

#include "Renderable Objects/Renderable.h"
#include "Renderable Objects/Phong/PhongRenderable.h"
#include "Renderable Objects/Solid/SolidRenderable.h"

#include "Shaders/ShaderLibrary.h"
#include "Camera.h"

namespace Ruby {
	class Renderer {
	public:
		Renderer() {
            glEnable(GL_DEPTH_TEST);
        }

        Renderer(Renderer&) = delete;
        Renderer& operator=(Renderer&) = delete;

        // One time calls
        void init(const Malachite::Matrix4f& projectionMatrix) {
            shaders.phongShader.use();
            ShaderProgram::upload("projection", projectionMatrix);

            shaders.solidShader.use();
            ShaderProgram::upload("projection", projectionMatrix);

            shaders.imageShader.use();
            ShaderProgram::upload("projection", projectionMatrix);

            shaders.directionalDepthShader.use();
            ShaderProgram::upload("projection", projectionMatrix);
        }


        // Per frame calls
        void prep(const Malachite::Matrix4f& viewMatrix) {
            /*glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);*/

            shaders.phongShader.use();
            ShaderProgram::upload("view", viewMatrix);

            shaders.solidShader.use();
            ShaderProgram::upload("view", viewMatrix);

            shaders.imageShader.use();
            ShaderProgram::upload("view", viewMatrix);

            shaders.directionalDepthShader.use();
            ShaderProgram::upload("view", viewMatrix);
        }

        void render(const Renderable& renderable) const {
            renderable.render();
        }

        void end() {

        }

        // Directional lighting rendering
        /*void directionalLightRenderingPrep() {
            shaders.directionalDepthShader.use();
        }

        void directionalLightRender(const Renderable& renderable) const {
            renderable.render();
        }

        void directionalLightRenderingEnd() const {

        }*/

        // Phong rendering
        void normalRenderingPrep() {
            shaders.phongShader.use();
        }

        void normalRender(const PhongRenderable& renderable) const {
            renderable.render();
        }

        void normalRenderingEnd() const {

        }

        // Solid rendering
        void solidRenderingPrep()  {
            shaders.solidShader.use();
        }

        void solidRender(const SolidRenderable& renderable) const {
            renderable.render();
        }

        void solidRenderingEnd() const {

        }
        
        ShaderLibrary shaders{ };
	};
}