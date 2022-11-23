#include "IOManager.h"

namespace Wavellite {
	IOManager::IOManager(Window* window)
		: window(window) {
		
	}


	Keyboard& IOManager::getKeyboard() {
		return m_Keyboard;
	}

	Mouse& IOManager::getMouse() {
		return m_Mouse;
	}
}