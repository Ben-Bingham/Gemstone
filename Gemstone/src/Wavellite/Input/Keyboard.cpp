#include "Keyboard.h"
#include "IOManager.h"

namespace Wavellite {
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
		Keyboard& keyboard = manager->getKeyboard();

		switch (key) {
		case GLFW_KEY_SPACE:			keyboard.KEY_SPACE = GLFWToState(action); break;
		case GLFW_KEY_APOSTROPHE:		keyboard.KEY_APOSTROPHE = GLFWToState(action); break;
		case GLFW_KEY_COMMA:			keyboard.KEY_COMMA = GLFWToState(action); break;
		case GLFW_KEY_MINUS:			keyboard.KEY_MINUS = GLFWToState(action); break;
		case GLFW_KEY_PERIOD:			keyboard.KEY_PERIOD = GLFWToState(action); break;
		case GLFW_KEY_SLASH:			keyboard.KEY_SLASH = GLFWToState(action); break;
		case GLFW_KEY_0:				keyboard.KEY_0 = GLFWToState(action); break;
		case GLFW_KEY_1:				keyboard.KEY_1 = GLFWToState(action); break;
		case GLFW_KEY_2:				keyboard.KEY_2 = GLFWToState(action); break;
		case GLFW_KEY_3:				keyboard.KEY_3 = GLFWToState(action); break;
		case GLFW_KEY_4:				keyboard.KEY_4 = GLFWToState(action); break;
		case GLFW_KEY_5:				keyboard.KEY_5 = GLFWToState(action); break;
		case GLFW_KEY_6:				keyboard.KEY_6 = GLFWToState(action); break;
		case GLFW_KEY_7:				keyboard.KEY_7 = GLFWToState(action); break;
		case GLFW_KEY_8:				keyboard.KEY_8 = GLFWToState(action); break;
		case GLFW_KEY_9:				keyboard.KEY_9 = GLFWToState(action); break;
		case GLFW_KEY_SEMICOLON:		keyboard.KEY_SEMICOLON = GLFWToState(action); break;
		case GLFW_KEY_EQUAL:			keyboard.KEY_EQUAL = GLFWToState(action); break;
		case GLFW_KEY_A:				keyboard.KEY_A = GLFWToState(action); break;
		case GLFW_KEY_B:				keyboard.KEY_B = GLFWToState(action); break;
		case GLFW_KEY_C:				keyboard.KEY_C = GLFWToState(action); break;
		case GLFW_KEY_D:				keyboard.KEY_D = GLFWToState(action); break;
		case GLFW_KEY_E:				keyboard.KEY_E = GLFWToState(action); break;
		case GLFW_KEY_F:				keyboard.KEY_F = GLFWToState(action); break;
		case GLFW_KEY_G:				keyboard.KEY_G = GLFWToState(action); break;
		case GLFW_KEY_H:				keyboard.KEY_H = GLFWToState(action); break;
		case GLFW_KEY_I:				keyboard.KEY_I = GLFWToState(action); break;
		case GLFW_KEY_J:				keyboard.KEY_J = GLFWToState(action); break;
		case GLFW_KEY_K:				keyboard.KEY_K = GLFWToState(action); break;
		case GLFW_KEY_L:				keyboard.KEY_L = GLFWToState(action); break;
		case GLFW_KEY_M:				keyboard.KEY_M = GLFWToState(action); break;
		case GLFW_KEY_N:				keyboard.KEY_N = GLFWToState(action); break;
		case GLFW_KEY_O:				keyboard.KEY_O = GLFWToState(action); break;
		case GLFW_KEY_P:				keyboard.KEY_P = GLFWToState(action); break;
		case GLFW_KEY_Q:				keyboard.KEY_Q = GLFWToState(action); break;
		case GLFW_KEY_R:				keyboard.KEY_R = GLFWToState(action); break;
		case GLFW_KEY_S:				keyboard.KEY_S = GLFWToState(action); break;
		case GLFW_KEY_T:				keyboard.KEY_T = GLFWToState(action); break;
		case GLFW_KEY_U:				keyboard.KEY_U = GLFWToState(action); break;
		case GLFW_KEY_V:				keyboard.KEY_V = GLFWToState(action); break;
		case GLFW_KEY_W:				keyboard.KEY_W = GLFWToState(action); break;
		case GLFW_KEY_X:				keyboard.KEY_X = GLFWToState(action); break;
		case GLFW_KEY_Y:				keyboard.KEY_Y = GLFWToState(action); break;
		case GLFW_KEY_Z:				keyboard.KEY_Z = GLFWToState(action); break;
		case GLFW_KEY_LEFT_BRACKET:		keyboard.KEY_LEFT_BRACKET = GLFWToState(action); break;
		case GLFW_KEY_BACKSLASH:		keyboard.KEY_BACKSLASH = GLFWToState(action); break;
		case GLFW_KEY_RIGHT_BRACKET:	keyboard.KEY_RIGHT_BRACKET = GLFWToState(action); break;
		case GLFW_KEY_GRAVE_ACCENT:		keyboard.KEY_GRAVE_ACCENT = GLFWToState(action); break;
		case GLFW_KEY_ESCAPE:			keyboard.KEY_ESCAPE = GLFWToState(action); break;
		case GLFW_KEY_ENTER:			keyboard.KEY_ENTER = GLFWToState(action); break;
		case GLFW_KEY_TAB:				keyboard.KEY_TAB = GLFWToState(action); break;
		case GLFW_KEY_BACKSPACE:		keyboard.KEY_BACKSPACE = GLFWToState(action); break;
		case GLFW_KEY_INSERT:			keyboard.KEY_INSERT = GLFWToState(action); break;
		case GLFW_KEY_DELETE:			keyboard.KEY_DELETE = GLFWToState(action); break;
		case GLFW_KEY_RIGHT:			keyboard.KEY_RIGHT = GLFWToState(action); break;
		case GLFW_KEY_LEFT:				keyboard.KEY_LEFT = GLFWToState(action); break;
		case GLFW_KEY_DOWN:				keyboard.KEY_DOWN = GLFWToState(action); break;
		case GLFW_KEY_UP:				keyboard.KEY_UP = GLFWToState(action); break;
		case GLFW_KEY_PAGE_UP:			keyboard.KEY_PAGE_UP = GLFWToState(action); break;
		case GLFW_KEY_PAGE_DOWN:		keyboard.KEY_PAGE_DOWN = GLFWToState(action); break;
		case GLFW_KEY_HOME:				keyboard.KEY_HOME = GLFWToState(action); break;
		case GLFW_KEY_END:				keyboard.KEY_END = GLFWToState(action); break;
		case GLFW_KEY_CAPS_LOCK:		keyboard.KEY_CAPS_LOCK = GLFWToState(action); break;
		case GLFW_KEY_SCROLL_LOCK:		keyboard.KEY_SCROLL_LOCK = GLFWToState(action); break;
		case GLFW_KEY_NUM_LOCK:			keyboard.KEY_NUM_LOCK = GLFWToState(action); break;
		case GLFW_KEY_PRINT_SCREEN:		keyboard.KEY_PRINT_SCREEN = GLFWToState(action); break;
		case GLFW_KEY_PAUSE:			keyboard.KEY_PAUSE = GLFWToState(action); break;
		case GLFW_KEY_F1:				keyboard.KEY_F1 = GLFWToState(action); break;
		case GLFW_KEY_F2:				keyboard.KEY_F2 = GLFWToState(action); break;
		case GLFW_KEY_F3:				keyboard.KEY_F3 = GLFWToState(action); break;
		case GLFW_KEY_F4:				keyboard.KEY_F4 = GLFWToState(action); break;
		case GLFW_KEY_F5:				keyboard.KEY_F5 = GLFWToState(action); break;
		case GLFW_KEY_F6:				keyboard.KEY_F6 = GLFWToState(action); break;
		case GLFW_KEY_F7:				keyboard.KEY_F7 = GLFWToState(action); break;
		case GLFW_KEY_F8:				keyboard.KEY_F8 = GLFWToState(action); break;
		case GLFW_KEY_F9:				keyboard.KEY_F9 = GLFWToState(action); break;
		case GLFW_KEY_F10:				keyboard.KEY_F10 = GLFWToState(action); break;
		case GLFW_KEY_F11:				keyboard.KEY_F11 = GLFWToState(action); break;
		case GLFW_KEY_F12:				keyboard.KEY_F12 = GLFWToState(action); break;
		case GLFW_KEY_KP_0:				keyboard.KEY_NUM_PAD_0 = GLFWToState(action); break;
		case GLFW_KEY_KP_1:				keyboard.KEY_NUM_PAD_1 = GLFWToState(action); break;
		case GLFW_KEY_KP_2:				keyboard.KEY_NUM_PAD_2 = GLFWToState(action); break;
		case GLFW_KEY_KP_3:				keyboard.KEY_NUM_PAD_3 = GLFWToState(action); break;
		case GLFW_KEY_KP_4:				keyboard.KEY_NUM_PAD_4 = GLFWToState(action); break;
		case GLFW_KEY_KP_5:				keyboard.KEY_NUM_PAD_5 = GLFWToState(action); break;
		case GLFW_KEY_KP_6:				keyboard.KEY_NUM_PAD_6 = GLFWToState(action); break;
		case GLFW_KEY_KP_7:				keyboard.KEY_NUM_PAD_7 = GLFWToState(action); break;
		case GLFW_KEY_KP_8:				keyboard.KEY_NUM_PAD_8 = GLFWToState(action); break;
		case GLFW_KEY_KP_9:				keyboard.KEY_NUM_PAD_9 = GLFWToState(action); break;
		case GLFW_KEY_KP_DECIMAL:		keyboard.KEY_NUM_PAD_DECIMAL = GLFWToState(action); break;
		case GLFW_KEY_KP_DIVIDE:		keyboard.KEY_NUM_PAD_DIVIDE = GLFWToState(action); break;
		case GLFW_KEY_KP_MULTIPLY:		keyboard.KEY_NUM_PAD_MULTIPLY = GLFWToState(action); break;
		case GLFW_KEY_KP_SUBTRACT:		keyboard.KEY_NUM_PAD_SUBTRACT = GLFWToState(action); break;
		case GLFW_KEY_KP_ADD:			keyboard.KEY_NUM_PAD_ADD = GLFWToState(action); break;
		case GLFW_KEY_KP_ENTER:			keyboard.KEY_NUM_PAD_ENTER = GLFWToState(action); break;
		case GLFW_KEY_KP_EQUAL:			keyboard.KEY_NUM_PAD_EQUAL = GLFWToState(action); break;
		case GLFW_KEY_LEFT_SHIFT:		keyboard.KEY_LEFT_SHIFT = GLFWToState(action); break;
		case GLFW_KEY_LEFT_CONTROL:		keyboard.KEY_LEFT_CONTROL = GLFWToState(action); break;
		case GLFW_KEY_LEFT_ALT:			keyboard.KEY_LEFT_ALT = GLFWToState(action); break;
		case GLFW_KEY_RIGHT_SHIFT:		keyboard.KEY_RIGHT_SHIFT = GLFWToState(action); break;
		case GLFW_KEY_RIGHT_CONTROL:	keyboard.KEY_RIGHT_CONTROL = GLFWToState(action); break;
		case GLFW_KEY_RIGHT_ALT:		keyboard.KEY_RIGHT_ALT = GLFWToState(action); break;
		default:								
		case GLFW_KEY_UNKNOWN:			keyboard.KEY_UNKNOWN = GLFWToState(action); break;
		}
	}
}