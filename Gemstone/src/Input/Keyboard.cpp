#include "pch.h"
#include "Keyboard.h"
#include "KeyboardEvents.h"
#include "Keys.h"

#include "Core/Engine.h"
#include "Core/Event System/EventHandler.h"

namespace Gem {
	void KeyCallback(GLFWwindow* window, int key, int scanCode, int action, int mods) {
		auto eventKey{ Key::UNKNOWN };

		switch (key) {
		case GLFW_KEY_SPACE:			eventKey = Key::SPACE; break;
		case GLFW_KEY_APOSTROPHE:		eventKey = Key::APOSTROPHE; break;		
		case GLFW_KEY_COMMA:			eventKey = Key::COMMA; break;			
		case GLFW_KEY_MINUS:			eventKey = Key::MINUS; break;			
		case GLFW_KEY_PERIOD:			eventKey = Key::PERIOD; break;			
		case GLFW_KEY_SLASH:			eventKey = Key::SLASH; break;			
		case GLFW_KEY_0:				eventKey = Key::ZERO; break;			
		case GLFW_KEY_1:				eventKey = Key::ONE; break;			
		case GLFW_KEY_2:				eventKey = Key::TWO; break;			
		case GLFW_KEY_3:				eventKey = Key::THREE; break;			
		case GLFW_KEY_4:				eventKey = Key::FOUR; break;			
		case GLFW_KEY_5:				eventKey = Key::FIVE; break;			
		case GLFW_KEY_6:				eventKey = Key::SIX; break;			
		case GLFW_KEY_7:				eventKey = Key::SEVEN; break;			
		case GLFW_KEY_8:				eventKey = Key::EIGHT; break;			
		case GLFW_KEY_9:				eventKey = Key::NINE; break;			
		case GLFW_KEY_SEMICOLON:		eventKey = Key::SEMICOLON; break;		
		case GLFW_KEY_EQUAL:			eventKey = Key::EQUAL; break;			
		case GLFW_KEY_A:				eventKey = Key::A; break;				
		case GLFW_KEY_B:				eventKey = Key::B; break;				
		case GLFW_KEY_C:				eventKey = Key::C; break;				
		case GLFW_KEY_D:				eventKey = Key::D; break;				
		case GLFW_KEY_E:				eventKey = Key::E; break;				
		case GLFW_KEY_F:				eventKey = Key::F; break;				
		case GLFW_KEY_G:				eventKey = Key::G; break;				
		case GLFW_KEY_H:				eventKey = Key::H; break;				
		case GLFW_KEY_I:				eventKey = Key::I; break;				
		case GLFW_KEY_J:				eventKey = Key::J; break;				
		case GLFW_KEY_K:				eventKey = Key::K; break;				
		case GLFW_KEY_L:				eventKey = Key::L; break;				
		case GLFW_KEY_M:				eventKey = Key::M; break;				
		case GLFW_KEY_N:				eventKey = Key::N; break;				
		case GLFW_KEY_O:				eventKey = Key::O; break;				
		case GLFW_KEY_P:				eventKey = Key::P; break;				
		case GLFW_KEY_Q:				eventKey = Key::Q; break;				
		case GLFW_KEY_R:				eventKey = Key::R; break;				
		case GLFW_KEY_S:				eventKey = Key::S; break;				
		case GLFW_KEY_T:				eventKey = Key::T; break;				
		case GLFW_KEY_U:				eventKey = Key::U; break;				
		case GLFW_KEY_V:				eventKey = Key::V; break;				
		case GLFW_KEY_W:				eventKey = Key::W; break;				
		case GLFW_KEY_X:				eventKey = Key::X; break;				
		case GLFW_KEY_Y:				eventKey = Key::Y; break;				
		case GLFW_KEY_Z:				eventKey = Key::Z; break;				
		case GLFW_KEY_LEFT_BRACKET:		eventKey = Key::LEFT_BRACKET; break;	
		case GLFW_KEY_BACKSLASH:		eventKey = Key::BACKSLASH; break;		
		case GLFW_KEY_RIGHT_BRACKET:	eventKey = Key::RIGHT_BRACKET; break;	
		case GLFW_KEY_GRAVE_ACCENT:		eventKey = Key::GRAVE_ACCENT; break;	
		case GLFW_KEY_ESCAPE:			eventKey = Key::ESCAPE; break;			
		case GLFW_KEY_ENTER:			eventKey = Key::ENTER; break;			
		case GLFW_KEY_TAB:				eventKey = Key::TAB; break;			
		case GLFW_KEY_BACKSPACE:		eventKey = Key::BACKSPACE; break;		
		case GLFW_KEY_INSERT:			eventKey = Key::INSERT; break;			
		case GLFW_KEY_DELETE:			eventKey = Key::DELETE; break;			
		case GLFW_KEY_RIGHT:			eventKey = Key::RIGHT; break;			
		case GLFW_KEY_LEFT:				eventKey = Key::LEFT; break;			
		case GLFW_KEY_DOWN:				eventKey = Key::DOWN; break;			
		case GLFW_KEY_UP:				eventKey = Key::UP; break;				
		case GLFW_KEY_PAGE_UP:			eventKey = Key::PAGE_UP; break;		
		case GLFW_KEY_PAGE_DOWN:		eventKey = Key::PAGE_DOWN; break;		
		case GLFW_KEY_HOME:				eventKey = Key::HOME; break;			
		case GLFW_KEY_END:				eventKey = Key::END; break;			
		case GLFW_KEY_CAPS_LOCK:		eventKey = Key::CAPS_LOCK; break;		
		case GLFW_KEY_SCROLL_LOCK:		eventKey = Key::SCROLL_LOCK; break;	
		case GLFW_KEY_NUM_LOCK:			eventKey = Key::NUM_LOCK; break;		
		case GLFW_KEY_PRINT_SCREEN:		eventKey = Key::PRINT_SCREEN; break;	
		case GLFW_KEY_PAUSE:			eventKey = Key::PAUSE; break;			
		case GLFW_KEY_F1:				eventKey = Key::F1; break;				
		case GLFW_KEY_F2:				eventKey = Key::F2; break;				
		case GLFW_KEY_F3:				eventKey = Key::F3; break;				
		case GLFW_KEY_F4:				eventKey = Key::F4; break;				
		case GLFW_KEY_F5:				eventKey = Key::F5; break;				
		case GLFW_KEY_F6:				eventKey = Key::F6; break;				
		case GLFW_KEY_F7:				eventKey = Key::F7; break;				
		case GLFW_KEY_F8:				eventKey = Key::F8; break;				
		case GLFW_KEY_F9:				eventKey = Key::F9; break;				
		case GLFW_KEY_F10:				eventKey = Key::F10; break;			
		case GLFW_KEY_F11:				eventKey = Key::F11; break;			
		case GLFW_KEY_F12:				eventKey = Key::F12; break;			
		case GLFW_KEY_KP_0:				eventKey = Key::NUM_PAD_0; break;		
		case GLFW_KEY_KP_1:				eventKey = Key::NUM_PAD_1; break;		
		case GLFW_KEY_KP_2:				eventKey = Key::NUM_PAD_2; break;		
		case GLFW_KEY_KP_3:				eventKey = Key::NUM_PAD_3; break;		
		case GLFW_KEY_KP_4:				eventKey = Key::NUM_PAD_4; break;		
		case GLFW_KEY_KP_5:				eventKey = Key::NUM_PAD_5; break;		
		case GLFW_KEY_KP_6:				eventKey = Key::NUM_PAD_6; break;		
		case GLFW_KEY_KP_7:				eventKey = Key::NUM_PAD_7; break;		
		case GLFW_KEY_KP_8:				eventKey = Key::NUM_PAD_8; break;		
		case GLFW_KEY_KP_9:				eventKey = Key::NUM_PAD_9; break;		
		case GLFW_KEY_KP_DECIMAL:		eventKey = Key::NUM_PAD_DECIMAL; break;
		case GLFW_KEY_KP_DIVIDE:		eventKey = Key::NUM_PAD_DIVIDE; break;	
		case GLFW_KEY_KP_MULTIPLY:		eventKey = Key::NUM_PAD_MULTIPLY; break;
		case GLFW_KEY_KP_SUBTRACT:		eventKey = Key::NUM_PAD_SUBTRACT; break;
		case GLFW_KEY_KP_ADD:			eventKey = Key::NUM_PAD_ADD; break;	
		case GLFW_KEY_KP_ENTER:			eventKey = Key::NUM_PAD_ENTER; break;	
		case GLFW_KEY_KP_EQUAL:			eventKey = Key::NUM_PAD_EQUAL; break;	
		case GLFW_KEY_LEFT_SHIFT:		eventKey = Key::LEFT_SHIFT; break;		
		case GLFW_KEY_LEFT_CONTROL:		eventKey = Key::LEFT_CONTROL; break;	
		case GLFW_KEY_LEFT_ALT:			eventKey = Key::LEFT_ALT; break;		
		case GLFW_KEY_RIGHT_SHIFT:		eventKey = Key::RIGHT_SHIFT; break;	
		case GLFW_KEY_RIGHT_CONTROL:	eventKey = Key::RIGHT_CONTROL; break;	
		case GLFW_KEY_RIGHT_ALT:		eventKey = Key::RIGHT_ALT; break;		
		default:								   
		case GLFW_KEY_UNKNOWN:			eventKey = Key::UNKNOWN; break;
		}

		if (action == GLFW_PRESS) {
			g_Engine.eventManager.Post(KeyboardEvents::KeyDown{ eventKey });
		}
		else if (action == GLFW_REPEAT) {
			g_Engine.eventManager.Post(KeyboardEvents::KeyHeld{ eventKey });
		}
		else if (action == GLFW_RELEASE) {
			g_Engine.eventManager.Post(KeyboardEvents::KeyUp{ eventKey });
		}
	}

	void Keyboard::StartUp() {
		const Window& window = g_Engine.window;
		HumanInterfaceDeviceContext& hidContext = g_Engine.humanInterfaceDeviceContext;

		hidContext.SetKeyCallback(window.Handle(), KeyCallback);
		hidContext.SetPointerToUserData(window.Handle(), "Keyboard", *this);
	}

	void Keyboard::ShutDown() { }

	bool Keyboard::GetKey(Key key) {
		return g_Engine.humanInterfaceDeviceContext.GetKey(g_Engine.window.Handle(), key);
	}
}