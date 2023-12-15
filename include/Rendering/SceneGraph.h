#pragma once
#include <list>
#include <vector>
#include "Material/IMaterial.h"
#include "Utility/Transform.h"

namespace Gem {
	struct Renderable {
		//InternalMesh mesh;
		IMaterial material;
		Transform transform;
	};

	struct Node {
		Renderable* self;
		std::list<Renderable*> children;
		Renderable* parent;
	};

	class SceneGraph {
	public:
		void AddRenderable(Renderable); //TODO cant copy renderable.

		Node world;
		std::vector<Renderable> bank;
	};
}