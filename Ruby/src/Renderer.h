#pragma once

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Log.h"

#include "Renderable Objects/Renderable.h"
#include "Renderable Objects/ShadowPhong/ShadowPhongRenderable.h"
#include "Renderable Objects/Solid/SolidRenderable.h"
#include "Renderable Objects/Phong/PhongRenderable.h"
#include "Renderable Objects/Debug/DebugRenderable.h"
#include "Renderable Objects/Image/ImageRenderable.h"

#include "Shaders/ShaderLibrary.h"
#include "Camera.h"
#include "Renderable Objects/Skybox.h"
#include "Renderable Objects/ScreenQuad/ScreenQuad.h"

namespace Ruby {
    void APIENTRY glDebugOutput(GLenum source, GLenum type, unsigned int id,
        GLenum severity, GLsizei length, const char* message, const void* userParam);

    class Renderer {
    public:
        Renderer() {
            glEnable(GL_DEPTH_TEST);

            //glEnable(GL_CULL_FACE);
            glCullFace(GL_BACK);
            glFrontFace(GL_CW);

            int flags;
            glGetIntegerv(GL_CONTEXT_FLAGS, &flags);

            if (flags & GL_CONTEXT_FLAG_DEBUG_BIT) {
                LOG("OpenGL debug context available.", Lazuli::LogLevel::INFO);
                glEnable(GL_DEBUG_OUTPUT);
                glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
                glDebugMessageCallback(glDebugOutput, nullptr);
                glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
            }
        }

        Renderer(Renderer&) = delete;
        Renderer& operator=(Renderer&) = delete;

        void addShader(ShaderProgram& program) {
            customPrograms.push_back(&program);
        }

        // One time calls
        void init(const Malachite::Matrix4f& projectionMatrix) {
            uploadProjectionMatrix(projectionMatrix);
        }

        void uploadProjectionMatrix(const Malachite::Matrix4f& projectionMatrix) {
            for (ShaderProgram* program : customPrograms) {
                program->use();
                ShaderProgram::upload("projection", projectionMatrix);
            }

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
            for (ShaderProgram* program : customPrograms) {
                program->use();
                ShaderProgram::upload("view", viewMatrix);
            }

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

        // ImGui
        void imGuiPrep() {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
        }

        void imGuiEnd() {
            ImGui::Render();

            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context); //TODO this has got to be expensive
        }

        void imGuiTerminate() {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();
        }

        // Screen Quad Rendering
        void screenQuadRenderingPrep() {
            shaders.screenQuadShader.use();
        }

        void screenQuadRender(const ScreenQuad& renderable) {
            renderable.render();
        }

        void screenQuadRenderingEnd() {

        }

        // Image Rendering
        void imageRenderingPrep() {
            shaders.imageShader.use();
        }

        void imageRender(const ImageRenderable& renderable) {
            renderable.render();
        }

        void imageRenderingEnd() {
	        
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

        // Debug rendering
        void debugRenderingPrep() {
            shaders.solidShader.use();
        }

        void debugRender(const DebugRenderable& renderable) const {
            renderable.render();
        }

        void debugRenderingEnd() const {

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

    private:
        std::vector<ShaderProgram*> customPrograms{};
	};
}