#include "Body.h" 
#include "SDL_image.h"
#define PI 3.14159265359

Body::Body(float mass_, float rotationalInertia_) {

	mass = mass_;
	rotationalInertia = rotationalInertia_;
	angle = 0.0f;
	angularVel = 0.0f;
	angularAcc = 0.0f;


	pos.Load(0, 0, 0);
	vel.Load(0, 0, 0);
	accel.Load(0, 0, 0);
	force.Load(0, 0, 0);

	radius = 1.0f;

}

Body::~Body() {} /// There is really nothing to do here - yet!


void Body::Update(const float deltaTime) {
	// calculating our angular velocity
	angle += (angularVel * deltaTime) + (0.5f * angularAcc*pow(deltaTime, 2));
	angularVel += angularAcc * deltaTime;

	double x, y;
	x = cos(angle * PI / 180.0) * force.x - sin(angle * PI / 180.0) * force.y;
	y = sin(angle * PI / 180.0) * force.x + cos(angle * PI / 180.0) * force.y;

	force.Load(x, y, 0);

	ApplyForce();

	//as stated above this set of code takes the forces from each axis and applies them to the body object. 
	pos.x += (vel.x * deltaTime) + (0.5f * accel.x * (deltaTime * deltaTime));
	pos.y += (vel.y * deltaTime) + (0.5f * accel.y * (deltaTime * deltaTime));
	pos.z += (vel.z * deltaTime) + (0.5f * accel.z * (deltaTime * deltaTime));

	vel.x += accel.x * deltaTime;
	vel.y += accel.y * deltaTime;
	vel.z += accel.z * deltaTime;


	/// Assuming all acceleration comes from an applied force - maybe not in the future - gravity!!

}

void Body::ApplyForce() {
	accel.x = force.x / mass;
	accel.y = force.y / mass;
	accel.z = force.z / mass;
}

void Body::ApplyTorque(float torque_) {

	torque = torque_;
	angularAcc = torque / rotationalInertia;

}

SDL_Surface* Body::getImage() {
	return bodyImage;
}