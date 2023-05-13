#pragma once

#include <tuple>

#include "Core/ISubSystem.h"
#include "Utility/Transform.h"

namespace Gem {
	class Mesh;
	class Material;

	class Renderer : ISubSystem{
	public:
		using Renderable = std::tuple<Transform*, Material*, Mesh*>; // TODO has no owenership over its components, needs to be changed

		Renderer() = default;

		void StartUp() override;
		void ShutDown() override;

		void Render();

		void Queue(Transform* transform, Material* material, Mesh* mesh);

	private:
		void RenderSetup();
		void RenderCleanup();

		std::vector<Renderable> m_Renderables;
	};
}