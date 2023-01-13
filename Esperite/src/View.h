#pragma once

#include "ComponentPool.h"
#include "Scene.h"

namespace Esperite {
	template<typename ...T>
	class View {
	public:
		View(Scene& scene)
			: m_Scene(&scene) {

            for (GameObject gb : scene.gameObjects) {
	            
            }

		}

        struct Iterator {
            Iterator() {}

            GameObject operator*() const {
                // give back the entityID we're currently at
            }

            bool operator==(const Iterator& other) const {
                // Compare two iterators
            }

            bool operator!=(const Iterator& other) const {
                // Similar to above
            }

            Iterator& operator++() {
                // Move the iterator forward
            }
        };

        const Iterator begin() const {
            // Give an iterator to the beginning of this view
        }

        const Iterator end() const {
            // Give an iterator to the end of this view 
        }

	private:
		Scene* m_Scene;
	};
}