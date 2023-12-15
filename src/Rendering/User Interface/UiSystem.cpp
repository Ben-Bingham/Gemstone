#include "pch.h"
#include "Rendering/User Interface/UiSystem.h"
#include "imgui.h"
#include "Core/Engine.h"
//#include "Entity Component System/ComponentView.h"

//#include "Rendering/Material/Material.h"

#include "Utility/Transform.h"

namespace Gem {
	//void UiSystem::Step(EntityManager& entityManager, float dt) {
	///*	if (!g_Engine.imGuiContext.imGuiIsActive) {
	//		return;
	//	}*/

	//	if (ImGui::Begin("Entity Component System")) {
	//		//for (auto gb : ComponentView{ entityManager }) {
	//		//	std::string gbIdString = "GameObject: " + std::to_string(gb);
	//		//	if (ImGui::CollapsingHeader(gbIdString.c_str())) {
	//		//		/*if (entityManager.HasComponent<Material>(gb)) {
	//		//			auto mat = entityManager.GetComponent<Material>(gb).iMaterial;
	//		//			if (std::dynamic_pointer_cast<DefaultMaterial>(mat) != nullptr) {
	//		//				DefaultMaterialUi(*std::dynamic_pointer_cast<DefaultMaterial>(mat), gb);
	//		//				ImGui::Separator();
	//		//			}
	//		//			if (std::dynamic_pointer_cast<SimpleMaterial>(mat) != nullptr) {
	//		//				SimpleMaterialUi(*std::dynamic_pointer_cast<SimpleMaterial>(mat), gb);
	//		//				ImGui::Separator();
	//		//			}
	//		//		}

	//		//		if (entityManager.HasComponent<Transform>(gb)) {
	//		//			TransformUi(entityManager.GetComponent<Transform>(gb), gb);
	//		//			ImGui::Separator();
	//		//		}*/
	//		//	}
	//		//}
	//	}
	//	ImGui::End();
	//}

	//void UiSystem::DefaultMaterialUi(const DefaultMaterial& material, size_t entityId) const {
	//	if (ImGui::TreeNode(std::string{ "Material##" + std::to_string(entityId) }.c_str())) {
	//		ImGui::Text("Diffuse:");
	//		ImGui::Bullet(); ImGui::Image(material.diffuse);

	//		ImGui::Text("Specular:");
	//		ImGui::Bullet(); ImGui::Image(material.specular);

	//		ImGui::TreePop();
	//	}
	//}

	//void UiSystem::SimpleMaterialUi(SimpleMaterial& material, size_t entityId) const {
	//	if (ImGui::TreeNode(std::string{ "Material##" + std::to_string(entityId) }.c_str())) {
	//		ImGui::Text("Colour:");
	//		Vector4f colourInFloat = material.colour.ToVec4f();
	//		const Vector4f colourInFloatBackup = colourInFloat;

	//		ImGui::Bullet(); ImGui::ColorPicker4("##Colour", colourInFloat.Data());

	//		if (colourInFloat != colourInFloatBackup) {
	//			material.colour.r = (unsigned char)std::floor(colourInFloat.x * 255.0f);
	//			material.colour.g = (unsigned char)std::floor(colourInFloat.y * 255.0f);
	//			material.colour.b = (unsigned char)std::floor(colourInFloat.z * 255.0f);
	//			material.colour.a = (unsigned char)std::floor(colourInFloat.w * 255.0f);
	//		}

	//		ImGui::TreePop();
	//	}
	//}

	//void UiSystem::TransformUi(Transform& transform, size_t entityId) const {
	//	if (ImGui::TreeNode(std::string{ "Transform##" + std::to_string(entityId) }.c_str())) {
	//		constexpr float dragSpeed = 0.1f;

	//		ImGui::Bullet(); ImGui::Text("Position:");
	//		ImGui::DragFloat3("##Pos", (float*)&transform.position, dragSpeed);

	//		ImGui::Bullet(); ImGui::Text("Scale:");
	//		ImGui::DragFloat3("##Scale", (float*)&transform.scale, dragSpeed);

	//		ImGui::Bullet(); ImGui::Text("Rotation:");
	//		ImGui::DragFloat3("##Rotation", (float*)&transform.rotation, dragSpeed);

	//		ImGui::TreePop();
	//	}
	//}
}