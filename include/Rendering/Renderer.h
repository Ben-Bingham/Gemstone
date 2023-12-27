#pragma once
#include "Renderable.h"
#include "Components/Camera.h"
#include "Gem.h"

namespace Gem {
	class MeshData;
	class IMaterial;

	class Renderer final {
	public:
		Renderer() = default;
		Renderer(const Renderer& other) = default;
		Renderer(Renderer&& other) noexcept = default;
		Renderer& operator=(const Renderer& other) = default;
		Renderer& operator=(Renderer&& other) noexcept = default;
		~Renderer() = default;

		void StartUp();
		void ShutDown();

		void RenderSetup();
		void Render();
		void RenderCleanup();

		void Queue(const Renderable& renderable);
		void AddCamera(const Camera& camera);

		// void AddCustomRenderProcess(std::function<void*> function);

	private:
		std::vector<Renderable> m_Renderables;
		std::vector<Camera> m_Cameras;

		// UPtr<FrameBuffer> m_PrimaryFrameBuffer; // TODO advanced rendering
		// UPtr<Texture> m_PrimaryFrameBufferColourComponent;
		// UPtr<RenderBuffer> m_PrimaryFrameBufferStencilAndDepthComponent;
	};
}