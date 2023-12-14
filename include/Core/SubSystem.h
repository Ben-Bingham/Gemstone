#pragma once

namespace Gem {
	class Engine;

	class SubSystem {
	public:
		SubSystem() = default;
		SubSystem(const SubSystem& other) = default;
		SubSystem(SubSystem&& other) noexcept = default;
		SubSystem& operator=(const SubSystem& other) = default;
		SubSystem& operator=(SubSystem&& other) noexcept = default;
		virtual ~SubSystem() = default;

		virtual void StartUp() = 0;
		virtual void ShutDown() = 0;
	};
}