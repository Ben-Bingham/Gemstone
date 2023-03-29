#pragma once
#include <GLFW/glfw3.h>

#include "Wavellite/HumanInterfaceDeviceContext.h"
#include "Wavellite/Window.h"

namespace Gem {
	enum KeyState {
		KEY_RELEASED = 0,
		KEY_PRESSED = 1,
		KEY_REPEAT = 2
	};

	void KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods);

	class Keyboard {
	public:
		Keyboard(Window& window, HumanInterfaceDeviceContext& hidContext);

		static KeyState GLFWToState(int action);
		void SetKeyCallback(void(*callback)(Keyboard& keyboard));

	private:
		Window& m_Window;
		HumanInterfaceDeviceContext& m_HidContext;

	public:
		std::vector<void(*)(Keyboard& keyboard)> keyCallbacks;

		KeyState KEY_SPACE{ KEY_RELEASED };
		KeyState KEY_APOSTROPHE{ KEY_RELEASED };
		KeyState KEY_COMMA{KEY_RELEASED};
		KeyState KEY_MINUS{KEY_RELEASED};
		KeyState KEY_PERIOD{KEY_RELEASED};
		KeyState KEY_SLASH{KEY_RELEASED};
		KeyState KEY_0{ KEY_RELEASED };
		KeyState KEY_1{ KEY_RELEASED };
		KeyState KEY_2{ KEY_RELEASED };
		KeyState KEY_3{ KEY_RELEASED };
		KeyState KEY_4{ KEY_RELEASED };
		KeyState KEY_5{ KEY_RELEASED };
		KeyState KEY_6{ KEY_RELEASED };
		KeyState KEY_7{ KEY_RELEASED };
		KeyState KEY_8{ KEY_RELEASED };
		KeyState KEY_9{ KEY_RELEASED };
		KeyState KEY_SEMICOLON{ KEY_RELEASED };
		KeyState KEY_EQUAL{KEY_RELEASED};
		KeyState KEY_A{ KEY_RELEASED };
		KeyState KEY_B{ KEY_RELEASED };
		KeyState KEY_C{ KEY_RELEASED };
		KeyState KEY_D{ KEY_RELEASED };
		KeyState KEY_E{ KEY_RELEASED };
		KeyState KEY_F{ KEY_RELEASED };
		KeyState KEY_G{ KEY_RELEASED };
		KeyState KEY_H{ KEY_RELEASED };
		KeyState KEY_I{ KEY_RELEASED };
		KeyState KEY_J{ KEY_RELEASED };
		KeyState KEY_K{ KEY_RELEASED };
		KeyState KEY_L{ KEY_RELEASED };
		KeyState KEY_M{ KEY_RELEASED };
		KeyState KEY_N{ KEY_RELEASED };
		KeyState KEY_O{ KEY_RELEASED };
		KeyState KEY_P{ KEY_RELEASED };
		KeyState KEY_Q{ KEY_RELEASED };
		KeyState KEY_R{ KEY_RELEASED };
		KeyState KEY_S{ KEY_RELEASED };
		KeyState KEY_T{ KEY_RELEASED };
		KeyState KEY_U{ KEY_RELEASED };
		KeyState KEY_V{ KEY_RELEASED };
		KeyState KEY_W{ KEY_RELEASED };
		KeyState KEY_X{ KEY_RELEASED };
		KeyState KEY_Y{ KEY_RELEASED };
		KeyState KEY_Z{ KEY_RELEASED };
		KeyState KEY_LEFT_BRACKET{ KEY_RELEASED };
		KeyState KEY_BACKSLASH{ KEY_RELEASED };
		KeyState KEY_RIGHT_BRACKET{KEY_RELEASED};
		KeyState KEY_GRAVE_ACCENT{ KEY_RELEASED };
		KeyState KEY_ESCAPE{ KEY_RELEASED };
		KeyState KEY_ENTER{ KEY_RELEASED };
		KeyState KEY_TAB{ KEY_RELEASED };
		KeyState KEY_BACKSPACE{ KEY_RELEASED };
		KeyState KEY_INSERT{ KEY_RELEASED };
		KeyState KEY_DELETE{ KEY_RELEASED };
		KeyState KEY_RIGHT{ KEY_RELEASED };
		KeyState KEY_LEFT{ KEY_RELEASED };
		KeyState KEY_DOWN{ KEY_RELEASED };
		KeyState KEY_UP{ KEY_RELEASED };
		KeyState KEY_PAGE_UP{ KEY_RELEASED };
		KeyState KEY_PAGE_DOWN{ KEY_RELEASED };
		KeyState KEY_HOME{ KEY_RELEASED };
		KeyState KEY_END{ KEY_RELEASED };
		KeyState KEY_CAPS_LOCK{ KEY_RELEASED };
		KeyState KEY_SCROLL_LOCK{ KEY_RELEASED };
		KeyState KEY_NUM_LOCK{ KEY_RELEASED };
		KeyState KEY_PRINT_SCREEN{ KEY_RELEASED };
		KeyState KEY_PAUSE{ KEY_RELEASED };
		KeyState KEY_F1{ KEY_RELEASED };
		KeyState KEY_F2{ KEY_RELEASED };
		KeyState KEY_F3{ KEY_RELEASED };
		KeyState KEY_F4{ KEY_RELEASED };
		KeyState KEY_F5{ KEY_RELEASED };
		KeyState KEY_F6{ KEY_RELEASED };
		KeyState KEY_F7{ KEY_RELEASED };
		KeyState KEY_F8{ KEY_RELEASED };
		KeyState KEY_F9{ KEY_RELEASED };
		KeyState KEY_F10{ KEY_RELEASED };
		KeyState KEY_F11{ KEY_RELEASED };
		KeyState KEY_F12{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_0{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_1{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_2{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_3{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_4{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_5{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_6{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_7{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_8{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_9{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_DECIMAL{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_DIVIDE{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_MULTIPLY{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_SUBTRACT{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_ADD{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_ENTER{ KEY_RELEASED };
		KeyState KEY_NUM_PAD_EQUAL{ KEY_RELEASED };
		KeyState KEY_LEFT_SHIFT{ KEY_RELEASED };
		KeyState KEY_LEFT_CONTROL{ KEY_RELEASED };
		KeyState KEY_LEFT_ALT{ KEY_RELEASED };
		KeyState KEY_RIGHT_SHIFT{ KEY_RELEASED };
		KeyState KEY_RIGHT_CONTROL{ KEY_RELEASED };
		KeyState KEY_RIGHT_ALT{ KEY_RELEASED };
		KeyState KEY_UNKNOWN{ KEY_RELEASED };
	};
}