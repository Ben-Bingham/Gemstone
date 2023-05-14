#pragma once

#include <tuple>

#include "Components/Camera.h"

#include "Core/ISubSystem.h"

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

		void Render();

		void Queue(const Ptr<InternalMesh>& mesh, const Ptr<InternalMaterial>& material, Matrix4f modelMatrix);
		void AddCamera(const Camera& camera);

	private:
		void RenderSetup();
		void RenderCleanup();

		std::vector<Renderable> m_Renderables;
		std::vector<Camera> m_Cameras;
	};
}