#pragma once

#include <GL/glew.h>

#include "Log.h"

#include "RenderableObject.h"

namespace Ruby {
	class Renderer {
	public:
		Renderer() {}

        void prep() {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
        }

        void render(RenderableObject renderable) {
            renderable.render();
        }

        void finish() {

        }
	};
}