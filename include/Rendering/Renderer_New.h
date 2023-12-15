#pragma once
#include "OpenGlContext.h"

#include "Core/SubSystem.h"

namespace Gem {
	class Renderer_New : SubSystem {
	public:
		Renderer_New(OpenGlContext& openGlContext);
		~Renderer_New() override = default;

		Renderer_New(const Renderer_New& other) = default;
		Renderer_New(Renderer_New&& other) noexcept = default;
		Renderer_New& operator=(const Renderer_New& other) = default;
		Renderer_New& operator=(Renderer_New&& other) noexcept = default;

		void StartUp() override;
		void ShutDown() override;

		void Render();

	private:
		OpenGlContext& m_Context;
		//SceneGraph m_SceneGraph; // TODO
	};
}