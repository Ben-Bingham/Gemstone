#pragma once
#include "Core/WindowEvents.h"
#include "Core/Event System/EventHandler.h"
#include "Input/KeyboardEvents.h"
#include "Input/MouseEvents.h"

namespace Gem {
<<<<<<< HEAD
	//class FpsCameraSystem : public System, EventHandler<KeyboardEvents::KeyDown>, EventHandler<WindowEvents::Resize> {
	//public:
	//	FpsCameraSystem() = delete;
	//	FpsCameraSystem(const FpsCameraSystem& other) = default;
	//	FpsCameraSystem(FpsCameraSystem&& other) noexcept = default;
	//	FpsCameraSystem& operator=(const FpsCameraSystem& other) = default;
	//	FpsCameraSystem& operator=(FpsCameraSystem&& other) noexcept = default;
	//	~FpsCameraSystem() override = default;
=======
	class FpsCameraSystem : public System, EventHandler<KeyboardEvents::KeyDown>, EventHandler<WindowEvents::Resize> {
	public:
		FpsCameraSystem() = delete;
		FpsCameraSystem(const FpsCameraSystem& other) = default;
		FpsCameraSystem(FpsCameraSystem&& other) noexcept = default;
		FpsCameraSystem& operator=(const FpsCameraSystem& other) = default;
		FpsCameraSystem& operator=(FpsCameraSystem&& other) noexcept = default;
		~FpsCameraSystem() override = default;
>>>>>>> c45902e481ceeaa56edb35b99852a647fa53ac3e

	//	void StartUp() override;
	//	void Step(EntityManager& entityManager, float dt) override;

	//	void HandleEvent(const KeyboardEvents::KeyDown& event) override;
	//	void HandleEvent(const WindowEvents::Resize& event) override;

	//private:
	//	bool m_MouseInputActive{ true };
	//	bool m_HasResized{ true };
	//};
}