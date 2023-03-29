#include "pch.h"

#include "Keyboard.h"
#include "Wavellite/Window.h"

namespace Gem {
	void KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods) {
		Keyboard& keyboard = HumanInterfaceDeviceContext::GetPointerToUserData<Keyboard>(window, "Keyboard");

		switch (key) {
		case GLFW_KEY_SPACE:			keyboard.KEY_SPACE = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_APOSTROPHE:		keyboard.KEY_APOSTROPHE = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_COMMA:			keyboard.KEY_COMMA = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_MINUS:			keyboard.KEY_MINUS = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_PERIOD:			keyboard.KEY_PERIOD = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_SLASH:			keyboard.KEY_SLASH = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_0:				keyboard.KEY_0 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_1:				keyboard.KEY_1 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_2:				keyboard.KEY_2 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_3:				keyboard.KEY_3 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_4:				keyboard.KEY_4 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_5:				keyboard.KEY_5 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_6:				keyboard.KEY_6 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_7:				keyboard.KEY_7 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_8:				keyboard.KEY_8 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_9:				keyboard.KEY_9 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_SEMICOLON:		keyboard.KEY_SEMICOLON = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_EQUAL:			keyboard.KEY_EQUAL = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_A:				keyboard.KEY_A = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_B:				keyboard.KEY_B = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_C:				keyboard.KEY_C = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_D:				keyboard.KEY_D = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_E:				keyboard.KEY_E = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_F:				keyboard.KEY_F = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_G:				keyboard.KEY_G = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_H:				keyboard.KEY_H = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_I:				keyboard.KEY_I = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_J:				keyboard.KEY_J = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_K:				keyboard.KEY_K = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_L:				keyboard.KEY_L = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_M:				keyboard.KEY_M = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_N:				keyboard.KEY_N = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_O:				keyboard.KEY_O = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_P:				keyboard.KEY_P = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_Q:				keyboard.KEY_Q = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_R:				keyboard.KEY_R = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_S:				keyboard.KEY_S = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_T:				keyboard.KEY_T = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_U:				keyboard.KEY_U = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_V:				keyboard.KEY_V = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_W:				keyboard.KEY_W = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_X:				keyboard.KEY_X = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_Y:				keyboard.KEY_Y = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_Z:				keyboard.KEY_Z = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_LEFT_BRACKET:		keyboard.KEY_LEFT_BRACKET = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_BACKSLASH:		keyboard.KEY_BACKSLASH = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_RIGHT_BRACKET:	keyboard.KEY_RIGHT_BRACKET = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_GRAVE_ACCENT:		keyboard.KEY_GRAVE_ACCENT = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_ESCAPE:			keyboard.KEY_ESCAPE = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_ENTER:			keyboard.KEY_ENTER = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_TAB:				keyboard.KEY_TAB = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_BACKSPACE:		keyboard.KEY_BACKSPACE = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_INSERT:			keyboard.KEY_INSERT = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_DELETE:			keyboard.KEY_DELETE = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_RIGHT:			keyboard.KEY_RIGHT = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_LEFT:				keyboard.KEY_LEFT = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_DOWN:				keyboard.KEY_DOWN = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_UP:				keyboard.KEY_UP = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_PAGE_UP:			keyboard.KEY_PAGE_UP = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_PAGE_DOWN:		keyboard.KEY_PAGE_DOWN = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_HOME:				keyboard.KEY_HOME = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_END:				keyboard.KEY_END = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_CAPS_LOCK:		keyboard.KEY_CAPS_LOCK = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_SCROLL_LOCK:		keyboard.KEY_SCROLL_LOCK = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_NUM_LOCK:			keyboard.KEY_NUM_LOCK = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_PRINT_SCREEN:		keyboard.KEY_PRINT_SCREEN = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_PAUSE:			keyboard.KEY_PAUSE = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_F1:				keyboard.KEY_F1 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_F2:				keyboard.KEY_F2 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_F3:				keyboard.KEY_F3 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_F4:				keyboard.KEY_F4 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_F5:				keyboard.KEY_F5 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_F6:				keyboard.KEY_F6 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_F7:				keyboard.KEY_F7 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_F8:				keyboard.KEY_F8 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_F9:				keyboard.KEY_F9 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_F10:				keyboard.KEY_F10 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_F11:				keyboard.KEY_F11 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_F12:				keyboard.KEY_F12 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_0:				keyboard.KEY_NUM_PAD_0 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_1:				keyboard.KEY_NUM_PAD_1 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_2:				keyboard.KEY_NUM_PAD_2 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_3:				keyboard.KEY_NUM_PAD_3 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_4:				keyboard.KEY_NUM_PAD_4 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_5:				keyboard.KEY_NUM_PAD_5 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_6:				keyboard.KEY_NUM_PAD_6 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_7:				keyboard.KEY_NUM_PAD_7 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_8:				keyboard.KEY_NUM_PAD_8 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_9:				keyboard.KEY_NUM_PAD_9 = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_DECIMAL:		keyboard.KEY_NUM_PAD_DECIMAL = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_DIVIDE:		keyboard.KEY_NUM_PAD_DIVIDE = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_MULTIPLY:		keyboard.KEY_NUM_PAD_MULTIPLY = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_SUBTRACT:		keyboard.KEY_NUM_PAD_SUBTRACT = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_ADD:			keyboard.KEY_NUM_PAD_ADD = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_ENTER:			keyboard.KEY_NUM_PAD_ENTER = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_KP_EQUAL:			keyboard.KEY_NUM_PAD_EQUAL = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_LEFT_SHIFT:		keyboard.KEY_LEFT_SHIFT = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_LEFT_CONTROL:		keyboard.KEY_LEFT_CONTROL = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_LEFT_ALT:			keyboard.KEY_LEFT_ALT = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_RIGHT_SHIFT:		keyboard.KEY_RIGHT_SHIFT = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_RIGHT_CONTROL:	keyboard.KEY_RIGHT_CONTROL = Keyboard::GLFWToState(action); break;
		case GLFW_KEY_RIGHT_ALT:		keyboard.KEY_RIGHT_ALT = Keyboard::GLFWToState(action); break;
		default:
		case GLFW_KEY_UNKNOWN:			keyboard.KEY_UNKNOWN = Keyboard::GLFWToState(action); break;
		}

		for (auto& callback : keyboard.keyCallbacks) {
			callback(keyboard);
		}
	}

	Keyboard::Keyboard(Window& window, HumanInterfaceDeviceContext& hidContext)
		: m_Window(window), m_HidContext(hidContext) {

		m_HidContext.SetKeyCallback(m_Window.Handle(), KeyCallback);

		m_HidContext.SetPointerToUserData(window.Handle(), "Keyboard", *this);
	}

	KeyState Keyboard::GLFWToState(const int action) {
		switch (action) {
		default:
		case GLFW_PRESS: return KEY_PRESSED;
		case GLFW_RELEASE: return KEY_RELEASED;
		case GLFW_REPEAT: return KEY_REPEAT;
		}
	}

	void Keyboard::SetKeyCallback(void(*callback)(Keyboard& keyboard)) {
		keyCallbacks.push_back(callback);
	}
}