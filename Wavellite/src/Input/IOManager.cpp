#include "IOManager.h"
#include "Window.h"

namespace Wavellite {
	IOManager::IOManager(Window& Window) : window(&Window) {}

	Keyboard* IOManager::getKeyboard() {
		return &m_Keyboard;
	}

	Mouse* IOManager::getMouse() {
		return &m_Mouse;
	}
}