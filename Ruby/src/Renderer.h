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
#include "Renderable Objects/SkyBox.h"
#include "Renderable Objects/ScreenQuad/ScreenQuad.h"

namespace Ruby {
    void APIENTRY glDebugOutput(GLenum source, GLenum type, unsigned int id,
        GLenum severity, GLsizei length, const char* message, const void* userParam);

    class Renderer {
    public:
        explicit Renderer(Camera& camera);
        Renderer(Renderer&) = delete;
        Renderer& operator=(Renderer&) = delete;
        Renderer(Renderer&&) = default;
        Renderer& operator=(Renderer&&) = default;
        ~Renderer() = default;

        void addCustomShader(ShaderProgram& program);

        // One time calls
        void init(const Malachite::Matrix4f& projectionMatrix) {
            uploadProjectionMatrix(projectionMatrix);
        }

        void uploadProjectionMatrix(const Malachite::Matrix4f& projectionMatrix) {
            for (ShaderProgram* program : m_CustomPrograms) {
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
        void prep();
        void end();

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

        void render(const PhongRenderable& renderable);
        void render(const SolidRenderable& renderable);
        void render(const DebugRenderable& renderable);
        void render(const ImageRenderable& renderable);
        void render(const ScreenQuad& renderable);
        void render(const SkyBox& skyBox);

        ShaderLibrary shaders{};

    private:
        std::vector<ShaderProgram*> m_CustomPrograms{};
    	Camera* m_Camera{ nullptr };
	};
}