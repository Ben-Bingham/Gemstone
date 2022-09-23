#pragma once

#include <GL/glew.h>

#include "Log.h"

#include "Renderable Objects/Renderable.h"
#include "Renderable Objects/Phong/PhongRenderable.h"
#include "Renderable Objects/Solid/SolidRenderable.h"

#include "Shaders/ShaderLibrary.h"

namespace Ruby {
	class Renderer {
	public:
		Renderer() {
            glEnable(GL_DEPTH_TEST);
        }

        void prep() {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void render(const Renderable& renderable) const {
            renderable.render();
        }

        void end() {

        }

        // Phong rendering
        void normalRenderingPrep() const {

        }

        void normalRender(const PhongRenderable& renderable) const {
            renderable.render();
        }

        void normalRenderingEnd() const {

        }

        // Solid rendering
        void solidRenderingPrep() const {

        }

        void solidRender(const SolidRenderable& renderable) const {
            renderable.render();
        }

        void solidRenderingEnd() const {

        }
        
        ShaderLibrary shaders{ };
	};
}