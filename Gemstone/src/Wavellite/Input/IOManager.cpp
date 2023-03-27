#include "pch.h"
#include "IOManager.h"
#include "Mouse.h"
#include "Keyboard.h"

namespace Wavellite {
	IOManager::IOManager()
		: keyboard(&Keyboard::Get()), mouse(&Mouse::Get()) {
		
	}

	// IOManager::IOManager(Window* window)
	// 	: window(window) {
	// 	
	// }
	//
	// Keyboard& IOManager::getKeyboard() {
	// 	return m_Keyboard;
	// }
	//
	// Mouse& IOManager::getMouse() {
	// 	return m_Mouse;
	// }
}