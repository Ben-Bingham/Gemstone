#pragma once

#include "Timing.h"

namespace Pyrite {
	class Physicist {
	public:
		Physicist(Wavellite::Time timeObj) 
			: time(timeObj){

		}

	private:
		Wavellite::Time time;
	};
}