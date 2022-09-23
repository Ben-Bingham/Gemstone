#include "Keyboard.h"
#include "IOManager.h"

namespace Ruby {
	KeyState GLFWToState(int action) {
		switch (action) {
		default:
		case GLFW_PRESS: return KeyState::KEY_PRESSED;
		case GLFW_RELEASE: return KeyState::KEY_RELEASED;
		case GLFW_REPEAT: return KeyState::KEY_REPEAT;
		}
	}

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		IOManager* manager = (IOManager*)glfwGetWindowUserPointer(window);

		switch (key) {
		case GLFW_KEY_SPACE:			manager->keyboard.KEY_SPACE = GLFWToState(action); break;
		case GLFW_KEY_APOSTROPHE:		manager->keyboard.KEY_APOSTROPHE = GLFWToState(action); break;
		case GLFW_KEY_COMMA:			manager->keyboard.KEY_COMMA = GLFWToState(action); break;
		case GLFW_KEY_MINUS:			manager->keyboard.KEY_MINUS = GLFWToState(action); break;
		case GLFW_KEY_PERIOD:			manager->keyboard.KEY_PERIOD = GLFWToState(action); break;
		case GLFW_KEY_SLASH:			manager->keyboard.KEY_SLASH = GLFWToState(action); break;
		case GLFW_KEY_0:				manager->keyboard.KEY_0 = GLFWToState(action); break;
		case GLFW_KEY_1:				manager->keyboard.KEY_1 = GLFWToState(action); break;
		case GLFW_KEY_2:				manager->keyboard.KEY_2 = GLFWToState(action); break;
		case GLFW_KEY_3:				manager->keyboard.KEY_3 = GLFWToState(action); break;
		case GLFW_KEY_4:				manager->keyboard.KEY_4 = GLFWToState(action); break;
		case GLFW_KEY_5:				manager->keyboard.KEY_5 = GLFWToState(action); break;
		case GLFW_KEY_6:				manager->keyboard.KEY_6 = GLFWToState(action); break;
		case GLFW_KEY_7:				manager->keyboard.KEY_7 = GLFWToState(action); break;
		case GLFW_KEY_8:				manager->keyboard.KEY_8 = GLFWToState(action); break;
		case GLFW_KEY_9:				manager->keyboard.KEY_9 = GLFWToState(action); break;
		case GLFW_KEY_SEMICOLON:		manager->keyboard.KEY_SEMICOLON = GLFWToState(action); break;
		case GLFW_KEY_EQUAL:			manager->keyboard.KEY_EQUAL = GLFWToState(action); break;
		case GLFW_KEY_A:				manager->keyboard.KEY_A = GLFWToState(action); break;
		case GLFW_KEY_B:				manager->keyboard.KEY_B = GLFWToState(action); break;
		case GLFW_KEY_C:				manager->keyboard.KEY_C = GLFWToState(action); break;
		case GLFW_KEY_D:				manager->keyboard.KEY_D = GLFWToState(action); break;
		case GLFW_KEY_E:				manager->keyboard.KEY_E = GLFWToState(action); break;
		case GLFW_KEY_F:				manager->keyboard.KEY_F = GLFWToState(action); break;
		case GLFW_KEY_G:				manager->keyboard.KEY_G = GLFWToState(action); break;
		case GLFW_KEY_H:				manager->keyboard.KEY_H = GLFWToState(action); break;
		case GLFW_KEY_I:				manager->keyboard.KEY_I = GLFWToState(action); break;
		case GLFW_KEY_J:				manager->keyboard.KEY_J = GLFWToState(action); break;
		case GLFW_KEY_K:				manager->keyboard.KEY_K = GLFWToState(action); break;
		case GLFW_KEY_L:				manager->keyboard.KEY_L = GLFWToState(action); break;
		case GLFW_KEY_M:				manager->keyboard.KEY_M = GLFWToState(action); break;
		case GLFW_KEY_N:				manager->keyboard.KEY_N = GLFWToState(action); break;
		case GLFW_KEY_O:				manager->keyboard.KEY_O = GLFWToState(action); break;
		case GLFW_KEY_P:				manager->keyboard.KEY_P = GLFWToState(action); break;
		case GLFW_KEY_Q:				manager->keyboard.KEY_Q = GLFWToState(action); break;
		case GLFW_KEY_R:				manager->keyboard.KEY_R = GLFWToState(action); break;
		case GLFW_KEY_S:				manager->keyboard.KEY_S = GLFWToState(action); break;
		case GLFW_KEY_T:				manager->keyboard.KEY_T = GLFWToState(action); break;
		case GLFW_KEY_U:				manager->keyboard.KEY_U = GLFWToState(action); break;
		case GLFW_KEY_V:				manager->keyboard.KEY_V = GLFWToState(action); break;
		case GLFW_KEY_W:				manager->keyboard.KEY_W = GLFWToState(action); break;
		case GLFW_KEY_X:				manager->keyboard.KEY_X = GLFWToState(action); break;
		case GLFW_KEY_Y:				manager->keyboard.KEY_Y = GLFWToState(action); break;
		case GLFW_KEY_Z:				manager->keyboard.KEY_Z = GLFWToState(action); break;
		case GLFW_KEY_LEFT_BRACKET:		manager->keyboard.KEY_LEFT_BRACKET = GLFWToState(action); break;
		case GLFW_KEY_BACKSLASH:		manager->keyboard.KEY_BACKSLASH = GLFWToState(action); break;
		case GLFW_KEY_RIGHT_BRACKET:	manager->keyboard.KEY_RIGHT_BRACKET = GLFWToState(action); break;
		case GLFW_KEY_GRAVE_ACCENT:		manager->keyboard.KEY_GRAVE_ACCENT = GLFWToState(action); break;
		case GLFW_KEY_ESCAPE:			manager->keyboard.KEY_ESCAPE = GLFWToState(action); break;
		case GLFW_KEY_ENTER:			manager->keyboard.KEY_ENTER = GLFWToState(action); break;
		case GLFW_KEY_TAB:				manager->keyboard.KEY_TAB = GLFWToState(action); break;
		case GLFW_KEY_BACKSPACE:		manager->keyboard.KEY_BACKSPACE = GLFWToState(action); break;
		case GLFW_KEY_INSERT:			manager->keyboard.KEY_INSERT = GLFWToState(action); break;
		case GLFW_KEY_DELETE:			manager->keyboard.KEY_DELETE = GLFWToState(action); break;
		case GLFW_KEY_RIGHT:			manager->keyboard.KEY_RIGHT = GLFWToState(action); break;
		case GLFW_KEY_LEFT:				manager->keyboard.KEY_LEFT = GLFWToState(action); break;
		case GLFW_KEY_DOWN:				manager->keyboard.KEY_DOWN = GLFWToState(action); break;
		case GLFW_KEY_UP:				manager->keyboard.KEY_UP = GLFWToState(action); break;
		case GLFW_KEY_PAGE_UP:			manager->keyboard.KEY_PAGE_UP = GLFWToState(action); break;
		case GLFW_KEY_PAGE_DOWN:		manager->keyboard.KEY_PAGE_DOWN = GLFWToState(action); break;
		case GLFW_KEY_HOME:				manager->keyboard.KEY_HOME = GLFWToState(action); break;
		case GLFW_KEY_END:				manager->keyboard.KEY_END = GLFWToState(action); break;
		case GLFW_KEY_CAPS_LOCK:		manager->keyboard.KEY_CAPS_LOCK = GLFWToState(action); break;
		case GLFW_KEY_SCROLL_LOCK:		manager->keyboard.KEY_SCROLL_LOCK = GLFWToState(action); break;
		case GLFW_KEY_NUM_LOCK:			manager->keyboard.KEY_NUM_LOCK = GLFWToState(action); break;
		case GLFW_KEY_PRINT_SCREEN:		manager->keyboard.KEY_PRINT_SCREEN = GLFWToState(action); break;
		case GLFW_KEY_PAUSE:			manager->keyboard.KEY_PAUSE = GLFWToState(action); break;
		case GLFW_KEY_F1:				manager->keyboard.KEY_F1 = GLFWToState(action); break;
		case GLFW_KEY_F2:				manager->keyboard.KEY_F2 = GLFWToState(action); break;
		case GLFW_KEY_F3:				manager->keyboard.KEY_F3 = GLFWToState(action); break;
		case GLFW_KEY_F4:				manager->keyboard.KEY_F4 = GLFWToState(action); break;
		case GLFW_KEY_F5:				manager->keyboard.KEY_F5 = GLFWToState(action); break;
		case GLFW_KEY_F6:				manager->keyboard.KEY_F6 = GLFWToState(action); break;
		case GLFW_KEY_F7:				manager->keyboard.KEY_F7 = GLFWToState(action); break;
		case GLFW_KEY_F8:				manager->keyboard.KEY_F8 = GLFWToState(action); break;
		case GLFW_KEY_F9:				manager->keyboard.KEY_F9 = GLFWToState(action); break;
		case GLFW_KEY_F10:				manager->keyboard.KEY_F10 = GLFWToState(action); break;
		case GLFW_KEY_F11:				manager->keyboard.KEY_F11 = GLFWToState(action); break;
		case GLFW_KEY_F12:				manager->keyboard.KEY_F12 = GLFWToState(action); break;
		case GLFW_KEY_KP_0:				manager->keyboard.KEY_NUM_PAD_0 = GLFWToState(action); break;
		case GLFW_KEY_KP_1:				manager->keyboard.KEY_NUM_PAD_1 = GLFWToState(action); break;
		case GLFW_KEY_KP_2:				manager->keyboard.KEY_NUM_PAD_2 = GLFWToState(action); break;
		case GLFW_KEY_KP_3:				manager->keyboard.KEY_NUM_PAD_3 = GLFWToState(action); break;
		case GLFW_KEY_KP_4:				manager->keyboard.KEY_NUM_PAD_4 = GLFWToState(action); break;
		case GLFW_KEY_KP_5:				manager->keyboard.KEY_NUM_PAD_5 = GLFWToState(action); break;
		case GLFW_KEY_KP_6:				manager->keyboard.KEY_NUM_PAD_6 = GLFWToState(action); break;
		case GLFW_KEY_KP_7:				manager->keyboard.KEY_NUM_PAD_7 = GLFWToState(action); break;
		case GLFW_KEY_KP_8:				manager->keyboard.KEY_NUM_PAD_8 = GLFWToState(action); break;
		case GLFW_KEY_KP_9:				manager->keyboard.KEY_NUM_PAD_9 = GLFWToState(action); break;
		case GLFW_KEY_KP_DECIMAL:		manager->keyboard.KEY_NUM_PAD_DECIMAL = GLFWToState(action); break;
		case GLFW_KEY_KP_DIVIDE:		manager->keyboard.KEY_NUM_PAD_DIVIDE = GLFWToState(action); break;
		case GLFW_KEY_KP_MULTIPLY:		manager->keyboard.KEY_NUM_PAD_MULTIPLY = GLFWToState(action); break;
		case GLFW_KEY_KP_SUBTRACT:		manager->keyboard.KEY_NUM_PAD_SUBTRACT = GLFWToState(action); break;
		case GLFW_KEY_KP_ADD:			manager->keyboard.KEY_NUM_PAD_ADD = GLFWToState(action); break;
		case GLFW_KEY_KP_ENTER:			manager->keyboard.KEY_NUM_PAD_ENTER = GLFWToState(action); break;
		case GLFW_KEY_KP_EQUAL:			manager->keyboard.KEY_NUM_PAD_EQUAL = GLFWToState(action); break;
		case GLFW_KEY_LEFT_SHIFT:		manager->keyboard.KEY_LEFT_SHIFT = GLFWToState(action); break;
		case GLFW_KEY_LEFT_CONTROL:		manager->keyboard.KEY_LEFT_CONTROL = GLFWToState(action); break;
		case GLFW_KEY_LEFT_ALT:			manager->keyboard.KEY_LEFT_ALT = GLFWToState(action); break;
		case GLFW_KEY_RIGHT_SHIFT:		manager->keyboard.KEY_RIGHT_SHIFT = GLFWToState(action); break;
		case GLFW_KEY_RIGHT_CONTROL:	manager->keyboard.KEY_RIGHT_CONTROL = GLFWToState(action); break;
		case GLFW_KEY_RIGHT_ALT:		manager->keyboard.KEY_RIGHT_ALT = GLFWToState(action); break;
		default:
		case GLFW_KEY_UNKNOWN:			manager->keyboard.KEY_UNKNOWN = GLFWToState(action); break;
		}
	}
}