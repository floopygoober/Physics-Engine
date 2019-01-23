#include "Collider.h"
#include "VMath.h"
#include "Body.h"

//here we check if the distance between both centre points is less than the radius of each body added together, if so we have collision. 
bool Collider::Collided(const Body& b1, const Body& b2) {
	float d = VMath::distance(b1.pos, b2.pos);
	//collision is true
	if (d < (b1.radius + b2.radius)) {
		return true;
	}
	//collision is false
	else return false;
}


void Collider::HandleCollision(Body& b1, Body& b2) {
	float bounciness = 1.0f;

	Vec3 lineOfAction = b2.pos - b1.pos;

	Vec3 nLineOfAction = VMath::normalize(lineOfAction);
	//here we have our math deciding the direction the bounce will sned each body in as well as the strength they bounce with
	float v1f = VMath::dot(b1.vel, nLineOfAction);
	float v2f = VMath::dot(b2.vel, nLineOfAction);
	float v1fnew = ((b1.mass - bounciness * b2.mass) * v1f + (1.0f + bounciness) * b2.mass * v2f) / (b1.mass + b2.mass);
	float v2fnew = ((b2.mass - bounciness * b1.mass) * v2f + (1.0f + bounciness) * b1.mass * v1f) / (b1.mass + b2.mass);
	b1.vel += (v1fnew - v1f) * nLineOfAction;
	b2.vel += (v2fnew - v2f) * nLineOfAction;
	return;
}

