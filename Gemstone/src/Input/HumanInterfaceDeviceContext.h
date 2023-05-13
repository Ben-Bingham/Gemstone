#pragma once
#include <GLFW/glfw3.h>

#include <unordered_map>

#include "Core/ISubSystem.h"
#include "Math/Vector.h"

namespace Gem {
	void ErrorCallback(int error, const char* description);

	using WindowHandle = GLFWwindow*;

	class HumanInterfaceDeviceContext final : ISubSystem {
	public:
		HumanInterfaceDeviceContext() = default;
		HumanInterfaceDeviceContext(const HumanInterfaceDeviceContext& other) = default;
		HumanInterfaceDeviceContext(HumanInterfaceDeviceContext&& other) noexcept = default;
		HumanInterfaceDeviceContext& operator=(const HumanInterfaceDeviceContext& other) = default;
		HumanInterfaceDeviceContext& operator=(HumanInterfaceDeviceContext&& other) noexcept = default;
		~HumanInterfaceDeviceContext() override = default;

		void StartUp() override;
		void ShutDown() override;

		void PollEvents() const;

		[[nodiscard]] WindowHandle CreateWindowHandle(const Vector2ui& size = Vector2ui{ 100, 100 }, const std::string& title = "Gemstone") const;
		void MakeGraphicsContextCurrent(WindowHandle handle);
		void CloseWindow(WindowHandle handle);
		bool ShouldWindowClose(WindowHandle handle);
		void SwapBuffers(WindowHandle handle);

		// Callbacks
		void SetKeyCallback(WindowHandle handle, void (*callback)(WindowHandle callbackHandle, int key, int scanCode, int action, int mods));
		void SetMouseButtonCallback(WindowHandle handle, void (*callback)(WindowHandle callbackHandle, int button, int action, int mods));
		void SetMousePositionCallback(WindowHandle handle, void (*callback)(WindowHandle callbackHandle, double xPos, double yPos));
		void SetScrollCallback(WindowHandle handle, void (*callback)(WindowHandle callbackHandle, double xOffset, double yOffset));
		void SetCursorEnterCallback(WindowHandle handle, void (*callback)(WindowHandle callbackHandle, int entered));

		template<typename T>
		void SetPointerToUserData(const WindowHandle handle, const std::string& key, T& data) {
			using Map = std::unordered_map<std::string, void*>;
			Map& windowData = *(Map*)glfwGetWindowUserPointer(handle);

			windowData[key] = (void*)&data;
		}

		template<typename T>
		[[nodiscard]] static T& GetPointerToUserData(const WindowHandle handle, const std::string& key) {
			using Map = std::unordered_map<std::string, void*>;
			Map& windowData = *(Map*)glfwGetWindowUserPointer(handle);

			return *(T*)windowData[key];
		}

	private:
		std::unordered_map<std::string, void*> m_UserWindowData{};
#ifdef GEMSTONE_DEBUG
		bool m_KeyCallbackInitialized{ false };
		bool m_MouseButtonCallbackInitialized{ false };
		bool m_MousePositionCallbackInitialized{ false };
		bool m_ScrollCallbackInitialized{ false };
		bool m_CursorEnterCallbackInitialized{ false };
#endif
	};
}