#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Celestite/Pointer.h"

#include "Malachite/Vector.h"

#include "Rutile/Interfaces/IWindowAPI.h"

namespace Rutile {
	class GlfwAPI : public IWindowAPI {
	public:
		GlfwAPI() = default;
		~GlfwAPI() override = default;

		void StartUp() override;
		void ShutDown() override;

		Celestite::Ptr<Ruby::WindowTarget> CreateWindow(const std::string& title, const Malachite::Vector2ui& size, bool visible) override;

	};
}