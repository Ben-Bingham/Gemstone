#pragma once
#include "Entity Component System/EntityManager.h"

#include "Rendering/Systems/RenderingSystem.h"

#include "Utility/Pointer.h"
#include "Utility/Transform.h"

namespace Gem {
	class ICamera {
	public:
		ICamera() = default;
		ICamera(const ICamera& other) = default;
		ICamera(ICamera&& other) noexcept = default;
		ICamera& operator=(const ICamera& other) = default;
		ICamera& operator=(ICamera&& other) noexcept = default;
		virtual ~ICamera() = default;

		Matrix4f projection{ 1.0f };
		Matrix4f view{ 1.0f };
	};

	class PerspectiveCamera final : public ICamera {
	public:
		PerspectiveCamera() = default;
		PerspectiveCamera(const PerspectiveCamera& other) = default;
		PerspectiveCamera(PerspectiveCamera&& other) noexcept = default;
		PerspectiveCamera& operator=(const PerspectiveCamera& other) = default;
		PerspectiveCamera& operator=(PerspectiveCamera&& other) noexcept = default;
		~PerspectiveCamera() override = default;

		Vector3f up{ Vector3f::up.normalize() };
		Vector3f forward{ Vector3f::north.normalize() };
		Vector3f right{ cross(up, forward).normalize() };

		Degree fov{ 90 };
		float movementSpeed{ 0.001f };
	};

	// This class acts as a component
	class Camera {
	public:
		enum class CameraType {
			PERSPECTIVE
		};

		Camera(CameraType camType);

		friend void RenderingSystem::Step(EntityManager& entityManager, float dt);

		Ptr<ICamera> Cam();
		CameraType type;

	private:
		Ptr<ICamera> m_Camera;
	};
}