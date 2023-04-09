#include "pch.h"
#include "Keyboard.h"
#include "KeyboardEvents.h"
#include "Core/Engine.h"
#include "Core/Event System/EventHandler.h"

namespace Gem {
	void KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods) {
		auto eventKey{ KeyboardEvents::Key::UNKNOWN };

		switch (key) {
		case GLFW_KEY_SPACE:			eventKey = KeyboardEvents::Key::SPACE; break;
		case GLFW_KEY_APOSTROPHE:		eventKey = KeyboardEvents::Key::APOSTROPHE; break;		
		case GLFW_KEY_COMMA:			eventKey = KeyboardEvents::Key::COMMA; break;			
		case GLFW_KEY_MINUS:			eventKey = KeyboardEvents::Key::MINUS; break;			
		case GLFW_KEY_PERIOD:			eventKey = KeyboardEvents::Key::PERIOD; break;			
		case GLFW_KEY_SLASH:			eventKey = KeyboardEvents::Key::SLASH; break;			
		case GLFW_KEY_0:				eventKey = KeyboardEvents::Key::ZERO; break;			
		case GLFW_KEY_1:				eventKey = KeyboardEvents::Key::ONE; break;			
		case GLFW_KEY_2:				eventKey = KeyboardEvents::Key::TWO; break;			
		case GLFW_KEY_3:				eventKey = KeyboardEvents::Key::THREE; break;			
		case GLFW_KEY_4:				eventKey = KeyboardEvents::Key::FOUR; break;			
		case GLFW_KEY_5:				eventKey = KeyboardEvents::Key::FIVE; break;			
		case GLFW_KEY_6:				eventKey = KeyboardEvents::Key::SIX; break;			
		case GLFW_KEY_7:				eventKey = KeyboardEvents::Key::SEVEN; break;			
		case GLFW_KEY_8:				eventKey = KeyboardEvents::Key::EIGHT; break;			
		case GLFW_KEY_9:				eventKey = KeyboardEvents::Key::NINE; break;			
		case GLFW_KEY_SEMICOLON:		eventKey = KeyboardEvents::Key::SEMICOLON; break;		
		case GLFW_KEY_EQUAL:			eventKey = KeyboardEvents::Key::EQUAL; break;			
		case GLFW_KEY_A:				eventKey = KeyboardEvents::Key::A; break;				
		case GLFW_KEY_B:				eventKey = KeyboardEvents::Key::B; break;				
		case GLFW_KEY_C:				eventKey = KeyboardEvents::Key::C; break;				
		case GLFW_KEY_D:				eventKey = KeyboardEvents::Key::D; break;				
		case GLFW_KEY_E:				eventKey = KeyboardEvents::Key::E; break;				
		case GLFW_KEY_F:				eventKey = KeyboardEvents::Key::F; break;				
		case GLFW_KEY_G:				eventKey = KeyboardEvents::Key::G; break;				
		case GLFW_KEY_H:				eventKey = KeyboardEvents::Key::H; break;				
		case GLFW_KEY_I:				eventKey = KeyboardEvents::Key::I; break;				
		case GLFW_KEY_J:				eventKey = KeyboardEvents::Key::J; break;				
		case GLFW_KEY_K:				eventKey = KeyboardEvents::Key::K; break;				
		case GLFW_KEY_L:				eventKey = KeyboardEvents::Key::L; break;				
		case GLFW_KEY_M:				eventKey = KeyboardEvents::Key::M; break;				
		case GLFW_KEY_N:				eventKey = KeyboardEvents::Key::N; break;				
		case GLFW_KEY_O:				eventKey = KeyboardEvents::Key::O; break;				
		case GLFW_KEY_P:				eventKey = KeyboardEvents::Key::P; break;				
		case GLFW_KEY_Q:				eventKey = KeyboardEvents::Key::Q; break;				
		case GLFW_KEY_R:				eventKey = KeyboardEvents::Key::R; break;				
		case GLFW_KEY_S:				eventKey = KeyboardEvents::Key::S; break;				
		case GLFW_KEY_T:				eventKey = KeyboardEvents::Key::T; break;				
		case GLFW_KEY_U:				eventKey = KeyboardEvents::Key::U; break;				
		case GLFW_KEY_V:				eventKey = KeyboardEvents::Key::V; break;				
		case GLFW_KEY_W:				eventKey = KeyboardEvents::Key::W; break;				
		case GLFW_KEY_X:				eventKey = KeyboardEvents::Key::X; break;				
		case GLFW_KEY_Y:				eventKey = KeyboardEvents::Key::Y; break;				
		case GLFW_KEY_Z:				eventKey = KeyboardEvents::Key::Z; break;				
		case GLFW_KEY_LEFT_BRACKET:		eventKey = KeyboardEvents::Key::LEFT_BRACKET; break;	
		case GLFW_KEY_BACKSLASH:		eventKey = KeyboardEvents::Key::BACKSLASH; break;		
		case GLFW_KEY_RIGHT_BRACKET:	eventKey = KeyboardEvents::Key::RIGHT_BRACKET; break;	
		case GLFW_KEY_GRAVE_ACCENT:		eventKey = KeyboardEvents::Key::GRAVE_ACCENT; break;	
		case GLFW_KEY_ESCAPE:			eventKey = KeyboardEvents::Key::ESCAPE; break;			
		case GLFW_KEY_ENTER:			eventKey = KeyboardEvents::Key::ENTER; break;			
		case GLFW_KEY_TAB:				eventKey = KeyboardEvents::Key::TAB; break;			
		case GLFW_KEY_BACKSPACE:		eventKey = KeyboardEvents::Key::BACKSPACE; break;		
		case GLFW_KEY_INSERT:			eventKey = KeyboardEvents::Key::INSERT; break;			
		case GLFW_KEY_DELETE:			eventKey = KeyboardEvents::Key::DELETE; break;			
		case GLFW_KEY_RIGHT:			eventKey = KeyboardEvents::Key::RIGHT; break;			
		case GLFW_KEY_LEFT:				eventKey = KeyboardEvents::Key::LEFT; break;			
		case GLFW_KEY_DOWN:				eventKey = KeyboardEvents::Key::DOWN; break;			
		case GLFW_KEY_UP:				eventKey = KeyboardEvents::Key::UP; break;				
		case GLFW_KEY_PAGE_UP:			eventKey = KeyboardEvents::Key::PAGE_UP; break;		
		case GLFW_KEY_PAGE_DOWN:		eventKey = KeyboardEvents::Key::PAGE_DOWN; break;		
		case GLFW_KEY_HOME:				eventKey = KeyboardEvents::Key::HOME; break;			
		case GLFW_KEY_END:				eventKey = KeyboardEvents::Key::END; break;			
		case GLFW_KEY_CAPS_LOCK:		eventKey = KeyboardEvents::Key::CAPS_LOCK; break;		
		case GLFW_KEY_SCROLL_LOCK:		eventKey = KeyboardEvents::Key::SCROLL_LOCK; break;	
		case GLFW_KEY_NUM_LOCK:			eventKey = KeyboardEvents::Key::NUM_LOCK; break;		
		case GLFW_KEY_PRINT_SCREEN:		eventKey = KeyboardEvents::Key::PRINT_SCREEN; break;	
		case GLFW_KEY_PAUSE:			eventKey = KeyboardEvents::Key::PAUSE; break;			
		case GLFW_KEY_F1:				eventKey = KeyboardEvents::Key::F1; break;				
		case GLFW_KEY_F2:				eventKey = KeyboardEvents::Key::F2; break;				
		case GLFW_KEY_F3:				eventKey = KeyboardEvents::Key::F3; break;				
		case GLFW_KEY_F4:				eventKey = KeyboardEvents::Key::F4; break;				
		case GLFW_KEY_F5:				eventKey = KeyboardEvents::Key::F5; break;				
		case GLFW_KEY_F6:				eventKey = KeyboardEvents::Key::F6; break;				
		case GLFW_KEY_F7:				eventKey = KeyboardEvents::Key::F7; break;				
		case GLFW_KEY_F8:				eventKey = KeyboardEvents::Key::F8; break;				
		case GLFW_KEY_F9:				eventKey = KeyboardEvents::Key::F9; break;				
		case GLFW_KEY_F10:				eventKey = KeyboardEvents::Key::F10; break;			
		case GLFW_KEY_F11:				eventKey = KeyboardEvents::Key::F11; break;			
		case GLFW_KEY_F12:				eventKey = KeyboardEvents::Key::F12; break;			
		case GLFW_KEY_KP_0:				eventKey = KeyboardEvents::Key::NUM_PAD_0; break;		
		case GLFW_KEY_KP_1:				eventKey = KeyboardEvents::Key::NUM_PAD_1; break;		
		case GLFW_KEY_KP_2:				eventKey = KeyboardEvents::Key::NUM_PAD_2; break;		
		case GLFW_KEY_KP_3:				eventKey = KeyboardEvents::Key::NUM_PAD_3; break;		
		case GLFW_KEY_KP_4:				eventKey = KeyboardEvents::Key::NUM_PAD_4; break;		
		case GLFW_KEY_KP_5:				eventKey = KeyboardEvents::Key::NUM_PAD_5; break;		
		case GLFW_KEY_KP_6:				eventKey = KeyboardEvents::Key::NUM_PAD_6; break;		
		case GLFW_KEY_KP_7:				eventKey = KeyboardEvents::Key::NUM_PAD_7; break;		
		case GLFW_KEY_KP_8:				eventKey = KeyboardEvents::Key::NUM_PAD_8; break;		
		case GLFW_KEY_KP_9:				eventKey = KeyboardEvents::Key::NUM_PAD_9; break;		
		case GLFW_KEY_KP_DECIMAL:		eventKey = KeyboardEvents::Key::NUM_PAD_DECIMAL; break;
		case GLFW_KEY_KP_DIVIDE:		eventKey = KeyboardEvents::Key::NUM_PAD_DIVIDE; break;	
		case GLFW_KEY_KP_MULTIPLY:		eventKey = KeyboardEvents::Key::NUM_PAD_MULTIPLY; break;
		case GLFW_KEY_KP_SUBTRACT:		eventKey = KeyboardEvents::Key::NUM_PAD_SUBTRACT; break;
		case GLFW_KEY_KP_ADD:			eventKey = KeyboardEvents::Key::NUM_PAD_ADD; break;	
		case GLFW_KEY_KP_ENTER:			eventKey = KeyboardEvents::Key::NUM_PAD_ENTER; break;	
		case GLFW_KEY_KP_EQUAL:			eventKey = KeyboardEvents::Key::NUM_PAD_EQUAL; break;	
		case GLFW_KEY_LEFT_SHIFT:		eventKey = KeyboardEvents::Key::LEFT_SHIFT; break;		
		case GLFW_KEY_LEFT_CONTROL:		eventKey = KeyboardEvents::Key::LEFT_CONTROL; break;	
		case GLFW_KEY_LEFT_ALT:			eventKey = KeyboardEvents::Key::LEFT_ALT; break;		
		case GLFW_KEY_RIGHT_SHIFT:		eventKey = KeyboardEvents::Key::RIGHT_SHIFT; break;	
		case GLFW_KEY_RIGHT_CONTROL:	eventKey = KeyboardEvents::Key::RIGHT_CONTROL; break;	
		case GLFW_KEY_RIGHT_ALT:		eventKey = KeyboardEvents::Key::RIGHT_ALT; break;		
		default:								   
		case GLFW_KEY_UNKNOWN:			eventKey = KeyboardEvents::Key::UNKNOWN; break;
		}

		if (action) {
			g_Engine.eventManager.Post(KeyboardEvents::KeyDown{ eventKey });
		}
	}

	void Keyboard::StartUp() {
		const Window& window = g_Engine.window;
		HumanInterfaceDeviceContext& hidContext = g_Engine.humanInterfaceDeviceContext;

		hidContext.SetKeyCallback(window.Handle(), KeyCallback);
		hidContext.SetPointerToUserData(window.Handle(), "Keyboard", *this);
	}

	void Keyboard::ShutDown() {
		
	}
}