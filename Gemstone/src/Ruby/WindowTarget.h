#pragma once
#include "IRenderingTarget.h"

namespace Ruby {
	class WindowTarget : public IRenderingTarget { //TODO rename to Window
	public:
		WindowTarget() = default;
		~WindowTarget() override = default;

		void Target() override;

		// GlfwWIndow* handle;

		/* TODO: Ignore the window created by GLFW when creating window, set it do invisible by default and dont even consider it a window, instead consider
		 * it as creating the "input handling, and timing context", than implement another class called "Screen" or similar that is actually the window itself
		 * When its created it would ask the "input handleing, and timing context" if it already has an invis window, if it does it would get the handle to that
		 * and use it, and other wise it would create a new window whille still using the same "input handeling, and imingi context"
		 *
		 *
		 * Maybe even make the initial window always invis, than just make additional visible windows after that can be used as the visible ones.
		 *
		 *
		 * The may be a potional issue with receiveing input if there is no window, it may be better to look for another window handeling lib that allows for a
		 * seprate context from window, would solve lots of problesm
		*/
	};
}