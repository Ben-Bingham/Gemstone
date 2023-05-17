#pragma once

#include <tuple>

#include "Components/Camera.h"

#include "Core/ISubSystem.h"

#include "OpenGl Objects/FrameBuffer.h"

#include "Utility/Pointer.h"
#include "Utility/Transform.h"

namespace Gem {
	class InternalMesh;
	class InternalMaterial;

	class Renderer final : ISubSystem{
	public:
		using Renderable = std::tuple<Ptr<InternalMesh>, Ptr<InternalMaterial>, Matrix4f>;

		Renderer() = default;

		void StartUp() override;
		void ShutDown() override;

		void RenderSetup();
		void Render();
		void RenderCleanup();

		void Queue(const Ptr<InternalMesh>& mesh, const Ptr<InternalMaterial>& material, Matrix4f modelMatrix);
		void AddCamera(const Camera& camera);

	private:
		std::vector<Renderable> m_Renderables;
		std::vector<Camera> m_Cameras;

		UPtr<FrameBuffer> m_PrimaryFrameBuffer;
		UPtr<Texture> m_PrimaryFrameBufferColourComponent;
		UPtr<RenderBuffer> m_PrimaryFrameBufferStencilAndDepthComponent;
	};
}