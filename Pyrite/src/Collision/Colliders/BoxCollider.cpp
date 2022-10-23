#include "BoxCollider.h"
#include "Collision/CollisionDetection.h"

namespace Pyrite {
	BoxCollider::BoxCollider(Point3D Dimensions, Point3D position) 
		: Collider(position), dimensions(Dimensions) {

	}

	bool BoxCollider::collidesWithBox(const BoxCollider* box) const {
		return CollisionDetection::boxWithBox(this, box);
	}
}