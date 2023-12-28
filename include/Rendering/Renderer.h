#pragma once
#include "CameraObject.h"
#include "OpenGlContext.h"
#include "Renderable.h"

namespace Gem {
	class Renderer {
		friend class Engine;

		static void StartUp();
		static void ShutDown();

		Renderer() = default;
		~Renderer() = default;

		static inline bool m_Started{ false };

	public:
		static Renderer& Get();

		Renderer(const Renderer& other) = delete;
		Renderer(Renderer&& other) noexcept = default;
		Renderer& operator=(const Renderer& other) = delete;
		Renderer& operator=(Renderer&& other) noexcept = default;

		void Render();

		std::vector<Renderable> renderables; // TODO this can be optimized, but it might not be necessary
		CameraObject camera;
	};
}