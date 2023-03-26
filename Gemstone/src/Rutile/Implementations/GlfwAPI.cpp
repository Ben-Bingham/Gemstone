#include "GlfwAPI.h"

#include "Lazuli/Log.h"

namespace Rutile {
	void GlfwAPI::StartUp() {
		if (!glfwInit()) {
			LOG("GLFW failed to initialized", Lazuli::LogLevel::TERMINAL);
		}
	}

	void GlfwAPI::ShutDown() {
		
	}

	Celestite::Ptr<Ruby::WindowTarget> GlfwAPI::CreateWindow(const std::string& title, const Malachite::Vector2ui& size, bool visible) {
		// glfwWindowHint(GLFW_VISIBLE, visible ? GLFW_TRUE : GLFW_FALSE);
		//
		// Celestite::Ptr<Ruby::WindowTarget> window = Celestite::CreatePtr<Ruby::WindowTarget>();
		// window->handle = glfwCreateWindow(size.x, size.y, title.c_str(), nullptr, nullptr);
		//
		//
		return nullptr;
	}
}