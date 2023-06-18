#include "pch.h"
#include "Camera.h"

#include "Core/Engine.h"

namespace Gem {
	Camera::Camera(const CameraType camType)
		: type(camType) {
		switch (camType) {
		case CameraType::FPS:
			m_Camera = CreatePtr<FpsCamera>();
			break;
		}

		if (m_Camera == nullptr) {
			LOG("Unreckognized Camera type.", LogLevel::ERROR);
		}
	}

	Ptr<ICamera> Camera::Cam() {
		return m_Camera;
	}
}