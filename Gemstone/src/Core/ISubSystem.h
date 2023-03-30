#pragma once

namespace Gem {
	class ISubSystem {
	public:
		ISubSystem() = default;
		ISubSystem(const ISubSystem& other) = default;
		ISubSystem(ISubSystem&& other) noexcept = default;
		ISubSystem& operator=(const ISubSystem& other) = default;
		ISubSystem& operator=(ISubSystem&& other) noexcept = default;
		virtual ~ISubSystem() = default;

		virtual void StartUp();
		virtual void ShutDown();
	};
}