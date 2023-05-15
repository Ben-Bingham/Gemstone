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

	class FpsCamera final : public ICamera {
	public:
		FpsCamera() = default;
		FpsCamera(const FpsCamera& other) = default;
		FpsCamera(FpsCamera&& other) noexcept = default;
		FpsCamera& operator=(const FpsCamera& other) = default;
		FpsCamera& operator=(FpsCamera&& other) noexcept = default;
		~FpsCamera() override = default;

		Vector3f up{ Vector3f::up.normalize() };
		Vector3f forward{ Vector3f::north.normalize() };
		Vector3f right{ cross(up, forward).normalize() };

		Degree fov{ 90 };
		float movementSpeed{ 6.0f };
		float mouseSensitivity{ 0.07f };

		Vector2i oldMousePosition{};
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