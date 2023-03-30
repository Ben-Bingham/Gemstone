#include "pch.h"
#include "ViewMatrixCorrection.h"

namespace Gem {
	void ViewMatrixCorrection::Step(EntityComponentSystem& ecs) {
		// for (auto& gb : scene->gameObjects) {
		// 	if (scene->HasComponent<Camera>(gb)
		// 		&& scene->HasComponent<Transform>(gb)) {
		// 		Camera* cam = scene->GetComponent<Camera>(gb);
		// 		Transform* transform = scene->GetComponent<Transform>(gb);
		//
		// 		cam->viewMatrix = lookAt(transform->position(), transform->position() + cam->forward, Vector3f::up);
		// 		//TODO not working is not factoring in mouse moving without moving person WORKING ON LAST
		// 	}
		// }
	}
}