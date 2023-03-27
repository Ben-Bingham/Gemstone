#include "pch.h"
#include "ViewMatrixCorrection.h"

#include "Ruby/Camera.h"

#include "Malachite/Utility/Transform.h"

namespace Ruby {
	void ViewMatrixCorrection::Step(Esperite::ECSScene* scene) {
		for (auto& gb : scene->gameObjects) {
			if (scene->HasComponent<Camera>(gb)
				&& scene->HasComponent<Malachite::Transform>(gb)) {
				Camera* cam = scene->GetComponent<Camera>(gb);
				Malachite::Transform* transform = scene->GetComponent<Malachite::Transform>(gb);

				cam->viewMatrix = lookAt(transform->position(), transform->position() + cam->forward, Malachite::Vector3f::up);
				//TODO not working is not factoring in mouse moving without moving person WORKING ON LAST
			}
		}
	}
}