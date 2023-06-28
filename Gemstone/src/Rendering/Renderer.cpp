#include "pch.h"

#include "Renderer.h"
#include "imgui.h"

#include "Core/Engine.h"
#include "Rendering/Components/Mesh.h"
#include "Rendering/Material/IMaterial.h"
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

	struct MeshRenderBucket {
		Ptr<InternalMesh> mesh;
		std::vector<Matrix4f> modelMatrices;
	};

	struct MaterialRenderBucket {
		Ptr<IMaterial> material;
		std::vector<MeshRenderBucket> meshRenderBuckets;
	};

	void Renderer::Render() {
#ifdef GEMSTONE_DEBUG
		if (m_Cameras.empty()) {
			LOG("No cameras provided, dont expect an image.", LogLevel::WARNING);
		}
#endif

		const float startTime = g_Engine.humanInterfaceDeviceContext.GetTime();

		for (auto& camera : m_Cameras) {
			std::vector<MaterialRenderBucket> materialBuckets;

			for (auto& [mesh, material, modelMatrix] : m_Renderables) {
				MaterialRenderBucket* materialRenderBucket{ nullptr };

				for (auto& materialBucket : materialBuckets) {
					if (typeid(*materialBucket.material) == typeid(*material)) {
						if (materialBucket.material != material) {
							continue;
						}
						materialRenderBucket = &materialBucket;
						break;
					}
				}

				if (materialRenderBucket == nullptr) {
					materialBuckets.push_back(MaterialRenderBucket{});
					materialBuckets.back().material = material;
					materialRenderBucket = &materialBuckets.back();
				}

				bool addedToMeshBucket{ false };
				for (auto& meshBucket : materialRenderBucket->meshRenderBuckets) {
					if (typeid(*meshBucket.mesh) == typeid(*mesh)) {
						meshBucket.modelMatrices.push_back(modelMatrix);
						addedToMeshBucket = true;
						break;
					}
				}

				if (!addedToMeshBucket) {
					materialRenderBucket->meshRenderBuckets.push_back(MeshRenderBucket{});
					materialRenderBucket->meshRenderBuckets.back().mesh = mesh;
					materialRenderBucket->meshRenderBuckets.back().modelMatrices.push_back(modelMatrix);
				}
			}

			for (auto& materialBucket : materialBuckets) {
				materialBucket.material->Apply();

				for (auto& meshBucket : materialBucket.meshRenderBuckets) {
					meshBucket.mesh->vao.Bind();

					for (auto& modelMatrix : meshBucket.modelMatrices) {
						// TODO this can now be more easily optimized with instanced rendering
						// TODO just need to find the best way to upload a large amount of possibly changing model matrices.
						Matrix4f mvp = modelMatrix * camera.Cam()->view * camera.Cam()->projection;
						materialBucket.material->shader->Upload("u_MVP", mvp);

						g_Engine.openGlContext.DrawElements(meshBucket.mesh->indexCount);
					}
				}

				materialBucket.material->Remove();
			}
		}

		const float renderTime = g_Engine.humanInterfaceDeviceContext.GetTime() - startTime;

		ImGui::Begin("Render Time");
		ImGui::Text("%3.5f", (double)renderTime);
		ImGui::End();
	}

	void Renderer::RenderCleanup() {
		g_Engine.window.SwapBuffers();
		m_Renderables.clear();
		m_Cameras.clear();
	}

	void Renderer::Queue(const Ptr<InternalMesh>& mesh, const Ptr<IMaterial>& material, Matrix4f modelMatrix) {
		m_Renderables.emplace_back(Renderable{ mesh, material, modelMatrix });
	}

	void Renderer::AddCamera(const Camera& camera) {
		m_Cameras.push_back(camera);
	}
}