#include "pch.h"
#include "Rendering/Renderer.h"
#include "imgui.h"
#include "Rendering/OpenGlContext.h"
#include "Rendering/Components/InternalMesh.h"
#include "Core/Engine.h"
#include "Rendering/Material/IMaterial.h"
#include "Core/Settings.h"

namespace Gem {
	void Renderer::StartUp() {
		//OpenGlContext& openGlContext = g_Engine.openGlContext;

		//openGlContext.EnableDepthTesting();
		//openGlContext.SetDepthTestFunction(OpenGlContext::DepthTestFunction::LESS_THAN);

		//openGlContext.EnableDepthMask();

		//openGlContext.EnableFaceCulling();
		//openGlContext.CullFace(OpenGlContext::CullableFaces::BACK);

		//openGlContext.SetFrontFaceDirection(OpenGlContext::FrontFaceDirection::CLOCKWISE);

		if (!Settings::vSync) {
			//g_Engine.humanInterfaceDeviceContext.SetSwapInterval(0);
		}

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
		//g_Engine.openGlContext.Clear();
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

					constexpr size_t NUMBER_OF_MESHES_REQUIRED_FOR_INSTANCED_RENDERING = 10;
					if (meshBucket.modelMatrices.size() >= NUMBER_OF_MESHES_REQUIRED_FOR_INSTANCED_RENDERING) {
						materialBucket.material->InstancedApply(); // TODO, not the best that we overwrite the first application of the material, maybe try and look forward at first application if it becomes an issue

						// materialBucket.material->shader->InstanceUpload(meshBucket.modelMatrices);

						// g_Engine.openGlContext.DrawInstanced();

						materialBucket.material->InstancedRemove();
					}

					for (auto& modelMatrix : meshBucket.modelMatrices) {
						// TODO this can now be more easily optimized with instanced rendering
						// TODO just need to find the best way to upload a large amount of possibly changing model matrices.
						Matrix4f mvp = modelMatrix * camera.Cam()->view * camera.Cam()->projection;
						materialBucket.material->shader->Upload("u_MVP", mvp);

						//g_Engine.openGlContext.DrawElements(meshBucket.mesh->indexCount);
					}
				}

				materialBucket.material->Remove();
			}
		}
	}

	void Renderer::RenderCleanup() {
		//g_Engine.window.SwapBuffers();
		m_Renderables.clear();
		m_Cameras.clear();
	}

	void Renderer::Queue(const Renderable& renderable) {
		m_Renderables.emplace_back(renderable);
	}

	void Renderer::AddCamera(const Camera& camera) {
		m_Cameras.push_back(camera);
	}
}