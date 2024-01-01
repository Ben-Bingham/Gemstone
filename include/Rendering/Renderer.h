#pragma once
#include "CameraObject.h"
#include "OpenGlContext.h"
#include "Renderable.h"

#include "Geometry/Cube.h"

#include "Meshes/MeshData.h"
#include "Meshes/MeshRegister.h"

#include "OpenGl Objects/GlBuffer.h"
#include "OpenGl Objects/VertexAttributeObject.h"

#include "Shaders/Shader.h"

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

		class Debug {
			struct DebugRenderable {
				std::vector<Vector3f> points;
				Colour colour;
			};

		public:
			Debug();

			void Add(Vector3f head, Vector3f tail, const Colour& colour = Colour::Red);

			void Render(Matrix4f view, Matrix4f projection);

			std::vector<DebugRenderable> debugRenderables;

		private:
			VertexAttributeObject m_Vao;
			VertexBuffer m_Vb;
			Shader m_Shader;

			//MeshData m_Point{ Cube{}.GetRawMesh() }; // TODO change to sphere abd implement

		} debug;

		void Render();

		std::vector<Renderable> renderables; // TODO this can be optimized, but it might not be necessary
		CameraObject camera;
	};
}