#pragma once

namespace Wavellite {
	class Keyboard;
	class Mouse;

	class IOManager {
	public:
		IOManager();

		Keyboard* keyboard;
		Mouse* mouse;
	};

// class Window;

	// class IOManager {
	// public:
	// 	IOManager(Window* window);
	//
	// 	Window* window;
	//
	// 	[[nodiscard]] Keyboard& getKeyboard();
	// 	[[nodiscard]] Mouse& getMouse();
	// private:
	// 	Keyboard m_Keyboard;
	// 	Mouse m_Mouse;
	// };
}