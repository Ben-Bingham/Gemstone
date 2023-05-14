#include "pch.h"
#include "UiSystem.h"
#include "imgui.h"

#include "Core/Engine.h"

#include "Entity Component System/ComponentView.h"
#include "Rendering/Components/Material.h"
#include "Utility/Transform.h"

namespace Gem {
	void UiSystem::Step(EntityManager& entityManager, float dt) {
		if (!g_Engine.imGuiContext.imGuiIsActive) {
			return;
		}

		if (ImGui::Begin("Entity Component System")) {
			for (auto gb : ComponentView{ entityManager }) {
				std::string gbIdString = "GameObject: " + std::to_string(gb);
				if (ImGui::CollapsingHeader(gbIdString.c_str())) {
					if (entityManager.HasComponent<Material>(gb)) {
						MaterialUi(entityManager.GetComponent<Material>(gb), gb);
						ImGui::Separator();
					}

					if (entityManager.HasComponent<Transform>(gb)) {
						TransformUi(entityManager.GetComponent<Transform>(gb), gb);
						ImGui::Separator();
					}
				}
			}
		}
		ImGui::End();
	}

	void UiSystem::MaterialUi(Material& material, size_t entityId) const {
		if (ImGui::TreeNode(std::string{ "Material##" + std::to_string(entityId) }.c_str())) {
			ImGui::Text("Diffuse:");
			ImGui::Bullet(); ImGui::Image(material.Diffuse());

			ImGui::Text("Specular:");
			ImGui::Bullet(); ImGui::Image(material.Specular());

			ImGui::TreePop();
		}
	}

	void UiSystem::TransformUi(Transform& transform, size_t entityId) const {
		if (ImGui::TreeNode(std::string{ "Transform##" + std::to_string(entityId) }.c_str())) {
			constexpr float dragSpeed = 0.1f;

			ImGui::Bullet(); ImGui::Text("Position:");
			ImGui::DragFloat3("##Pos", (float*)&transform.position, dragSpeed);

			ImGui::Bullet(); ImGui::Text("Scale:");
			ImGui::DragFloat3("##Scale", (float*)&transform.scale, dragSpeed);

			ImGui::Bullet(); ImGui::Text("Rotation:");
			ImGui::DragFloat3("##Rotation", (float*)&transform.rotation, dragSpeed);

			ImGui::TreePop();
		}
	}
}