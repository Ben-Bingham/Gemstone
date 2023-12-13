#pragma once
#include "Camera.h"

#include "ECS/GameObject.h"

namespace Emerald {
	class CameraGameObject : public GameObject {
	public:
		template<typename ... Args>
		CameraGameObject(Args&& ... args)
			: m_Camera(std::forward<Args>(args)...) {

		}

		Ruby::Camera& cameraRef() { return m_Camera; }

	private:
		Ruby::Camera m_Camera;
	};
}