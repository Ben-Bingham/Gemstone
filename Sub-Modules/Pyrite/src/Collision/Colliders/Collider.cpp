#include "Collider.h"

namespace Pyrite {
	Collider::Collider(Point3D Position)
		: position(Position) { }

	bool Collider::Collision::operator==(const Collider::Collision& other) const {
		return (this->localA == other.localA) &&
			(this->localB == other.localB) &&
			(this->normal == other.normal) &&
			(this->depth == other.depth) &&
			(this->hasCollision == other.hasCollision);
	}
}