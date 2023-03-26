#pragma once
#include "Apatite/ISubSystem.h"

namespace Wavellite {
	void ErrorCallback(int error, const char* description);

	class GLFWContext : public Apatite::ISubSystem{
	public:
		GLFWContext() = default;
		GLFWContext(const GLFWContext& other) = default;
		GLFWContext(GLFWContext&& other) noexcept = default;
		GLFWContext& operator=(const GLFWContext& other) = default;
		GLFWContext& operator=(GLFWContext&& other) noexcept = default;
		~GLFWContext() override = default;

		void StartUp() override;
		void ShutDown() override;
	};
}