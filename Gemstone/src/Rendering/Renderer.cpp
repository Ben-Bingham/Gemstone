#include "pch.h"

#include "Renderer.h"

#include "Core/Engine.h"
#include "Rendering/Components/Mesh.h"
#include "Rendering/Components/Material.h"

namespace Gem {
	void Renderer::StartUp() {
		OpenGlContext& openGlContext = g_Engine.openGlContext;

		openGlContext.EnableDepthTesting();
		openGlContext.SetDepthTestFunction(OpenGlContext::DepthTestFunction::LESS_THAN);

		openGlContext.EnableDepthMask();

		openGlContext.EnableFaceCulling();
		openGlContext.CullFace(OpenGlContext::CullableFaces::BACK);

		openGlContext.SetFrontFaceDirection(OpenGlContext::FrontFaceDirection::CLOCKWISE);

		// m_PrimaryFrameBuffer = CreateUPtr<FrameBuffer>();
		// m_PrimaryFrameBufferColourComponent = CreateUPtr<Texture>();
		// m_PrimaryFrameBufferStencilAndDepthComponent = CreateUPtr<RenderBuffer>();
		//
		// m_PrimaryFrameBuffer->Bind();
		// m_PrimaryFrameBuffer->AttachTexture(*m_PrimaryFrameBufferColourComponent);
		// m_PrimaryFrameBuffer->AttachRenderBuffer(*m_PrimaryFrameBufferStencilAndDepthComponent);
		// m_PrimaryFrameBuffer->Compile();
		// m_PrimaryFrameBuffer->Unbind();
	}

	void Renderer::ShutDown() { }

	void Renderer::RenderSetup() {
		g_Engine.openGlContext.Clear();
	}

	void Renderer::Render() {
#ifdef GEMSTONE_DEBUG
		if (m_Cameras.empty()) {
			LOG("No cameras provided, dont expect an image.", LogLevel::WARNING);
		}
#endif

		for (auto& camera : m_Cameras) {
			for (auto& [mesh, material, modelMatrix] : m_Renderables) {
				mesh->vao.Bind();

				material->shader->Bind();

				Texture::ActivateUnit(0);
				material->diffuse.Bind();
				material->shader->Upload("u_Diffuse", 0);

				Texture::ActivateUnit(1);
				material->specular.Bind();
				material->shader->Upload("u_Specular", 1);

				Matrix4f mvp = modelMatrix * camera.Cam()->view * camera.Cam()->projection;
				material->shader->Upload("u_MVP", mvp);

				g_Engine.openGlContext.DrawElements(mesh->indexCount);
			}
		}
	}

	void Renderer::RenderCleanup() {
		g_Engine.window.SwapBuffers();
		m_Renderables.clear();
		m_Cameras.clear();
	}

	void Renderer::Queue(const Ptr<InternalMesh>& mesh, const Ptr<InternalMaterial>& material, Matrix4f modelMatrix) {
		m_Renderables.emplace_back(Renderable{ mesh, material, modelMatrix });
	}

	void Renderer::AddCamera(const Camera& camera) {
		m_Cameras.push_back(camera);
	}
}