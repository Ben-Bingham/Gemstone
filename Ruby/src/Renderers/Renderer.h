#pragma once

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shaders/ShaderLibrary.h"
#include "Camera.h"
#include "DebugRenderer.h"
#include "Scene.h"
#include "System.h"

#include "Renderable Objects/Renderable.h"
#include "Window.h"

namespace Ruby {
    void APIENTRY glDebugOutput(GLenum source, GLenum type, unsigned int id,
        GLenum severity, GLsizei length, const char* message, const void* userParam);

    void DefaultRenderFunction(Esperite::Scene* scene, Camera* camera);

    class DebugRenderer; //TODO remove

    class Renderer : public Esperite::System {
    public:
    	Renderer(Wavellite::Window& window, Camera* camera = nullptr);

        Renderer(Renderer&) = delete;
        Renderer& operator=(Renderer&) = delete;
        Renderer(Renderer&&) = default;
        Renderer& operator=(Renderer&&) = default;
        ~Renderer() override = default;

        // Per frame calls
        void beginFrame(); //TODO remove these functions
        void endFrame();

        void PreStep(Esperite::Scene* scene) override;
        void Step(Esperite::Scene* scene) override;
        void EndStep(Esperite::Scene* scene) override;

        template<typename... T>
        void debugRender(T...args) {
            m_DebugRenderer.queue(args...);
        }

        ShaderLibrary& shaders{ ShaderLibrary::Get() };

        void setCamera(Camera* camera) {
            m_Camera = camera;
        }

        // void AddRenderFunction(void (*renderFunction)(Esperite::Scene* scene, Camera* camera));

        void Render(const Renderable& renderable, Camera* camera);

        // void SubmitRenderCall(Esperite::Scene* scene, Esperite::GameObject gb);

        class GUI {
        public:
            static void StartUp();
            static void Begin();
            static void End();
            static void ShutDown();

        private:
            GUI() = default;
        };

        std::vector<void (*)(Esperite::Scene* scene, Camera* camera)> renderFunctions;

        void (*defaultRenderFunction)(Esperite::Scene* scene, Camera* camera){ DefaultRenderFunction };

    private:
    	Camera* m_Camera{ nullptr };
        Wavellite::Window* m_Window{ nullptr };

        DebugRenderer m_DebugRenderer{ this };

        // Malachite::Matrix4f m_ViewMatrix{ 1.0f };

        std::vector<Renderable> m_Renderables;
        std::vector<Camera*> m_Cameras;
        // std::vector<void (*)(Esperite::Scene* scene)> m_ImGuiFunctions;
        // std::vector<Celestite::Ptr<Renderable>> m_OldRenderables;

        // bool m_Changed{ true };

        // struct MeshBucket {
        //     Celestite::Ptr<MeshData> mesh;
        //     std::vector<Celestite::Ptr<Renderable>> renderables;
        // };
        //
        // struct MaterialBucket {
        //     Celestite::Ptr<MaterialData> material;
        //     std::vector<Celestite::Ptr<Renderable>> renderables;
        //     std::vector<MeshBucket> meshBuckets;
        // };


        // std::vector<MaterialBucket> m_Buckets;

	};

}