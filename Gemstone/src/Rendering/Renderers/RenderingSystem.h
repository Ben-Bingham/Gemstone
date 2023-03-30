#pragma once

#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "DebugRenderer.h"

#include "Core/Window.h"

#include "Entity Component System/Scene.h"
#include "Entity Component System/System.h"



#include "Rendering/Camera.h"
#include "Rendering/Renderable Objects/Renderable.h"
#include "Rendering/Shaders/ShaderLibrary.h"

namespace Gem {
    void APIENTRY glDebugOutput(GLenum source, GLenum type, unsigned int id,
        GLenum severity, GLsizei length, const char* message, const void* userParam);

    void DefaultRenderFunction(Gem::Scene* scene, Camera* camera);

    class DebugRenderer; //TODO remove

    class RenderingSystem : public Gem::System {
    public:
    	RenderingSystem(Gem::Window& window, Camera* camera = nullptr);

        RenderingSystem(RenderingSystem&) = delete;
        RenderingSystem& operator=(RenderingSystem&) = delete;
        RenderingSystem(RenderingSystem&&) = default;
        RenderingSystem& operator=(RenderingSystem&&) = default;
        ~RenderingSystem() override = default;

        // Per frame calls
        void beginFrame(); //TODO remove these functions
        void endFrame();

        // void PreStep(Gem::Scene* scene) override;
        // void Step(Gem::Scene* scene) override;
        // void EndStep(Gem::Scene* scene) override;

        template<typename... T>
        void debugRender(T...args) {
            m_DebugRenderer.queue(args...);
        }

        ShaderLibrary& shaders{ ShaderLibrary::Get() };

        void setCamera(Camera* camera) {
            m_Camera = camera;
        }

        // void AddRenderFunction(void (*renderFunction)(Gem::Scene* scene, Camera* camera));

        void Render(const Renderable& renderable, Camera* camera);

        // void SubmitRenderCall(Gem::Scene* scene, Gem::InternalGameObject gb);

        class GUI {
        public:
            static void StartUp();
            static void Begin();
            static void End();
            static void ShutDown();

        private:
            GUI() = default;
        };

        std::vector<void (*)(Gem::Scene* scene, Camera* camera)> renderFunctions;

        void (*defaultRenderFunction)(Gem::Scene* scene, Camera* camera){ DefaultRenderFunction };

    private:
    	Camera* m_Camera{ nullptr };
        Gem::Window* m_Window{ nullptr };

        DebugRenderer m_DebugRenderer{ this };

        // Matrix4f m_ViewMatrix{ 1.0f };

        std::vector<Renderable> m_Renderables;
        std::vector<Camera*> m_Cameras;
        // std::vector<void (*)(Gem::Scene* scene)> m_ImGuiFunctions;
        // std::vector<Ptr<Renderable>> m_OldRenderables;

        // bool m_Changed{ true };

        // struct MeshBucket {
        //     Ptr<MeshData> mesh;
        //     std::vector<Ptr<Renderable>> renderables;
        // };
        //
        // struct MaterialBucket {
        //     Ptr<MaterialData> material;
        //     std::vector<Ptr<Renderable>> renderables;
        //     std::vector<MeshBucket> meshBuckets;
        // };


        // std::vector<MaterialBucket> m_Buckets;

	};

}