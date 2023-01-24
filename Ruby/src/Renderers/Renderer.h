#pragma once

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shaders/ShaderLibrary.h"
#include "Camera.h"
#include "DebugRenderer.h"
#include "Renderable Objects/Renderable.h"
#include "Window.h"

namespace Ruby {
    void APIENTRY glDebugOutput(GLenum source, GLenum type, unsigned int id,
        GLenum severity, GLsizei length, const char* message, const void* userParam);

    class DebugRenderer;

    class Renderer : public Esperite::System {
    public:
    	Renderer(Wavellite::Window& window, Camera* camera = nullptr);

        Renderer(Renderer&) = delete;
        Renderer& operator=(Renderer&) = delete;
        Renderer(Renderer&&) = default;
        Renderer& operator=(Renderer&&) = default;
        ~Renderer() override = default;

        // Per frame calls
        void beginFrame();
        void endFrame();

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

        void Step(Esperite::Scene* scene) override;

        template<typename... T>
        void debugRender(T...args) {
            m_DebugRenderer.queue(args...);
        }

        ShaderLibrary& shaders{ ShaderLibrary::get() };

        void setCamera(Camera* camera) {
            m_Camera = camera;
        }

    private:
    	Camera* m_Camera{ nullptr };
        Wavellite::Window* m_Window{ nullptr };

        DebugRenderer m_DebugRenderer{ this };

        Malachite::Matrix4f m_ViewMatrix{ 1.0f };

        std::vector<Renderable> m_Renderables;
        std::vector<Celestite::Ptr<Renderable>> m_OldRenderables;

        bool m_Changed{ true };

        struct MeshBucket {
            Celestite::Ptr<MeshData> mesh;
            std::vector<Celestite::Ptr<Renderable>> renderables;
        };

        struct MaterialBucket {
            Celestite::Ptr<MaterialData> material;
            std::vector<Celestite::Ptr<Renderable>> renderables;
            std::vector<MeshBucket> meshBuckets;
        };


        std::vector<MaterialBucket> m_Buckets;

	};
}