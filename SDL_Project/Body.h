#ifndef BODY_H
#define BODY_H
#include "Vector.h"
#include "SDL.h"
#include "Collider.h"
using namespace MATH; 

class Body {
	friend class Collider;

public:
	Vec3 pos;
	Vec3 vel;
	Vec3 accel;
	Vec3 force;

	float mass;
	float radius;
	float rotationalInertia;
	float angle;
	float angularVel;
	float angularAcc;
	float torque;

private:
	SDL_Surface *bodyImage;
	
public:
	Body(float mass_, float rotationalInertia_);
	~Body();
	void Update(const float deltaTime);
	void ApplyForce();
	void ApplyTorque(float torque_);

	/// Just a little helper function
	SDL_Surface* getImage();
};


#endif
