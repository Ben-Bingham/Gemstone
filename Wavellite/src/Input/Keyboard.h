#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Wavellite {
	enum KeyState {
		KEY_RELEASED = 0,
		KEY_PRESSED = 1,
		KEY_REPEAT = 2
	};

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	class Keyboard {
	public:
		Keyboard() = default;
		Keyboard(const Keyboard&) = delete;
		const Keyboard& operator=(const Keyboard&) = delete;
		Keyboard(Keyboard&&) = default;
		Keyboard& operator=(Keyboard&&) = default;
		~Keyboard() = default;

		KeyState KEY_SPACE{ KeyState::KEY_RELEASED };
		KeyState KEY_APOSTROPHE{ KeyState::KEY_RELEASED };
		KeyState KEY_COMMA{ KeyState::KEY_RELEASED };
		KeyState KEY_MINUS{ KeyState::KEY_RELEASED };
		KeyState KEY_PERIOD{ KeyState::KEY_RELEASED };
		KeyState KEY_SLASH{ KeyState::KEY_RELEASED };
		KeyState KEY_0{ KeyState::KEY_RELEASED };
		KeyState KEY_1{ KeyState::KEY_RELEASED };
		KeyState KEY_2{ KeyState::KEY_RELEASED };
		KeyState KEY_3{ KeyState::KEY_RELEASED };
		KeyState KEY_4{ KeyState::KEY_RELEASED };
		KeyState KEY_5{ KeyState::KEY_RELEASED };
		KeyState KEY_6{ KeyState::KEY_RELEASED };
		KeyState KEY_7{ KeyState::KEY_RELEASED };
		KeyState KEY_8{ KeyState::KEY_RELEASED };
		KeyState KEY_9{ KeyState::KEY_RELEASED };
		KeyState KEY_SEMICOLON{ KeyState::KEY_RELEASED };
		KeyState KEY_EQUAL{ KeyState::KEY_RELEASED };
		KeyState KEY_A{ KeyState::KEY_RELEASED };
		KeyState KEY_B{ KeyState::KEY_RELEASED };
		KeyState KEY_C{ KeyState::KEY_RELEASED };
		KeyState KEY_D{ KeyState::KEY_RELEASED };
		KeyState KEY_E{ KeyState::KEY_RELEASED };
		KeyState KEY_F{ KeyState::KEY_RELEASED };
		KeyState KEY_G{ KeyState::KEY_RELEASED };
		KeyState KEY_H{ KeyState::KEY_RELEASED };
		KeyState KEY_I{ KeyState::KEY_RELEASED };
		KeyState KEY_J{ KeyState::KEY_RELEASED };
		KeyState KEY_K{ KeyState::KEY_RELEASED };
		KeyState KEY_L{ KeyState::KEY_RELEASED };
		KeyState KEY_M{ KeyState::KEY_RELEASED };
		KeyState KEY_N{ KeyState::KEY_RELEASED };
		KeyState KEY_O{ KeyState::KEY_RELEASED };
		KeyState KEY_P{ KeyState::KEY_RELEASED };
		KeyState KEY_Q{ KeyState::KEY_RELEASED };
		KeyState KEY_R{ KeyState::KEY_RELEASED };
		KeyState KEY_S{ KeyState::KEY_RELEASED };
		KeyState KEY_T{ KeyState::KEY_RELEASED };
		KeyState KEY_U{ KeyState::KEY_RELEASED };
		KeyState KEY_V{ KeyState::KEY_RELEASED };
		KeyState KEY_W{ KeyState::KEY_RELEASED };
		KeyState KEY_X{ KeyState::KEY_RELEASED };
		KeyState KEY_Y{ KeyState::KEY_RELEASED };
		KeyState KEY_Z{ KeyState::KEY_RELEASED };
		KeyState KEY_LEFT_BRACKET{ KeyState::KEY_RELEASED };
		KeyState KEY_BACKSLASH{ KeyState::KEY_RELEASED };
		KeyState KEY_RIGHT_BRACKET{ KeyState::KEY_RELEASED };
		KeyState KEY_GRAVE_ACCENT{ KeyState::KEY_RELEASED };
		KeyState KEY_ESCAPE{ KeyState::KEY_RELEASED };
		KeyState KEY_ENTER{ KeyState::KEY_RELEASED };
		KeyState KEY_TAB{ KeyState::KEY_RELEASED };
		KeyState KEY_BACKSPACE{ KeyState::KEY_RELEASED };
		KeyState KEY_INSERT{ KeyState::KEY_RELEASED };
		KeyState KEY_DELETE{ KeyState::KEY_RELEASED };
		KeyState KEY_RIGHT{ KeyState::KEY_RELEASED };
		KeyState KEY_LEFT{ KeyState::KEY_RELEASED };
		KeyState KEY_DOWN{ KeyState::KEY_RELEASED };
		KeyState KEY_UP{ KeyState::KEY_RELEASED };
		KeyState KEY_PAGE_UP{ KeyState::KEY_RELEASED };
		KeyState KEY_PAGE_DOWN{ KeyState::KEY_RELEASED };
		KeyState KEY_HOME{ KeyState::KEY_RELEASED };
		KeyState KEY_END{ KeyState::KEY_RELEASED };
		KeyState KEY_CAPS_LOCK{ KeyState::KEY_RELEASED };
		KeyState KEY_SCROLL_LOCK{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_LOCK{ KeyState::KEY_RELEASED };
		KeyState KEY_PRINT_SCREEN{ KeyState::KEY_RELEASED };
		KeyState KEY_PAUSE{ KeyState::KEY_RELEASED };
		KeyState KEY_F1{ KeyState::KEY_RELEASED };
		KeyState KEY_F2{ KeyState::KEY_RELEASED };
		KeyState KEY_F3{ KeyState::KEY_RELEASED };
		KeyState KEY_F4{ KeyState::KEY_RELEASED };
		KeyState KEY_F5{ KeyState::KEY_RELEASED };
		KeyState KEY_F6{ KeyState::KEY_RELEASED };
		KeyState KEY_F7{ KeyState::KEY_RELEASED };
		KeyState KEY_F8{ KeyState::KEY_RELEASED };
		KeyState KEY_F9{ KeyState::KEY_RELEASED };
		KeyState KEY_F10{ KeyState::KEY_RELEASED };
		KeyState KEY_F11{ KeyState::KEY_RELEASED };
		KeyState KEY_F12{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_0{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_1{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_2{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_3{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_4{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_5{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_6{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_7{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_8{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_9{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_DECIMAL{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_DIVIDE{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_MULTIPLY{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_SUBTRACT{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_ADD{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_ENTER{ KeyState::KEY_RELEASED };
		KeyState KEY_NUM_PAD_EQUAL{ KeyState::KEY_RELEASED };
		KeyState KEY_LEFT_SHIFT{ KeyState::KEY_RELEASED };
		KeyState KEY_LEFT_CONTROL{ KeyState::KEY_RELEASED };
		KeyState KEY_LEFT_ALT{ KeyState::KEY_RELEASED };
		KeyState KEY_RIGHT_SHIFT{ KeyState::KEY_RELEASED };
		KeyState KEY_RIGHT_CONTROL{ KeyState::KEY_RELEASED };
		KeyState KEY_RIGHT_ALT{ KeyState::KEY_RELEASED };
		KeyState KEY_UNKNOWN{ KeyState::KEY_RELEASED };
	};

	KeyState GLFWToState(int action);
}