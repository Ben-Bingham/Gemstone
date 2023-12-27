#pragma once
#include "CameraObject.h"
#include "OpenGlContext.h"
#include "Renderable.h"

namespace Gem {
	class Renderer_New {
		friend class Engine;

		static void StartUp();
		static void ShutDown();

		Renderer_New() = default;
		~Renderer_New() = default;

		static inline bool m_Started{ false };

	public:
		static Renderer_New& Get();

		Renderer_New(const Renderer_New& other) = delete;
		Renderer_New(Renderer_New&& other) noexcept = default;
		Renderer_New& operator=(const Renderer_New& other) = delete;
		Renderer_New& operator=(Renderer_New&& other) noexcept = default;

		void Render();

		std::vector<Renderable> renderables; // TODO this can be optimized, but it might not be necessary
		CameraObject camera;
	};
}