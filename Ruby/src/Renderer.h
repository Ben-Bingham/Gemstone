#pragma once

#include <GL/glew.h>

#include "Log.h"

#include "Renderable Objects/Renderable.h"
#include "Renderable Objects/ShadowPhong/ShadowPhongRenderable.h"
#include "Renderable Objects/Solid/SolidRenderable.h"
#include "Renderable Objects/Phong/PhongRenderable.h"

#include "Shaders/ShaderLibrary.h"
#include "Camera.h"
#include "Renderable Objects/Skybox.h"

namespace Ruby {
	class Renderer {
	public:
		Renderer() {
            glEnable(GL_DEPTH_TEST);

            glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            glFrontFace(GL_CW);
        }

        Renderer(Renderer&) = delete;
        Renderer& operator=(Renderer&) = delete;

        // One time calls
        void init(const Malachite::Matrix4f& projectionMatrix) {
            shaders.shadowPhongShader.use();
            ShaderProgram::upload("projection", projectionMatrix);

            shaders.solidShader.use();
            ShaderProgram::upload("projection", projectionMatrix);

            shaders.imageShader.use();
            ShaderProgram::upload("projection", projectionMatrix);

            shaders.directionalDepthShader.use();
            ShaderProgram::upload("projection", projectionMatrix);

            shaders.skyboxShader.use();
            ShaderProgram::upload("projection", projectionMatrix);

            shaders.phongShader.use();
            ShaderProgram::upload("projection", projectionMatrix);
        }

        // Per frame calls
        void prep(const Malachite::Matrix4f& viewMatrix) {
            shaders.shadowPhongShader.use();
            ShaderProgram::upload("view", viewMatrix);

            shaders.solidShader.use();
            ShaderProgram::upload("view", viewMatrix);

            shaders.imageShader.use();
            ShaderProgram::upload("view", viewMatrix);

            shaders.directionalDepthShader.use();
            ShaderProgram::upload("view", viewMatrix);

            Malachite::Matrix4f skyboxView = Malachite::Matrix4f{
                Malachite::Vector4f{viewMatrix.row1.x, viewMatrix.row1.y, viewMatrix.row1.z, 0.0f},
                Malachite::Vector4f{viewMatrix.row2.x, viewMatrix.row2.y, viewMatrix.row2.z, 0.0f},
                Malachite::Vector4f{viewMatrix.row3.x, viewMatrix.row3.y, viewMatrix.row3.z, 0.0f},
                Malachite::Vector4f{0.0f, 0.0f, 0.0f, 1.0f}
            };

            shaders.skyboxShader.use();
            ShaderProgram::upload("view", skyboxView);

            shaders.phongShader.use();
            ShaderProgram::upload("view", viewMatrix);

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void end() {

        }

        // Directional lighting rendering
        void directionalLightRenderingPrep() {
            shaders.directionalDepthShader.use();
        }

        void directionalLightRender(const Renderable& renderable) const {
            renderable.render();
        }

        void directionalLightRenderingEnd(unsigned int width, unsigned int height) const {
            glViewport(0, 0, width, height);
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        // Shadow Phong rendering
        void shadowPhongRenderingPrep() {
            shaders.shadowPhongShader.use();
        }

        void shadowPhongRender(const ShadowPhongRenderable& renderable) const {
            renderable.render();
        }

        void shadowPhongRenderingEnd() const {

        }

        // Phong rendering
        void phongRenderingPrep() {
            shaders.phongShader.use();
        }

        void phongRender(const PhongRenderable& renderable) const {
            renderable.render();
        }

        void phongRenderingEnd() const {

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

        // Skybox rendering
        void skyboxRenderingPrep() {
            shaders.skyboxShader.use();
            glDepthMask(GL_FALSE);
            glCullFace(GL_FRONT);
            glDepthFunc(GL_LEQUAL);
        }

        void skyboxRender(const Skybox& skybox) const {
            skybox.render();
        }
        
        void skyboxRenderingEnd() const {
            glDepthFunc(GL_LESS);
            glCullFace(GL_BACK);
            glDepthMask(GL_TRUE);
        }

        ShaderLibrary shaders{ };
	};
}