#include "Assignment1.h"
#include "Body.h"
#include <SDL.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#define time 1

using namespace std;
//constructor
Assignment1::Assignment1(){
	
	elapsedTime = 0.0f;

	body = nullptr;
	
	OnCreate();
}
//destrcutor
Assignment1::~Assignment1(){
}
//creates a body with a mass and rotational inertia 
bool Assignment1::OnCreate() {
		
	body = new Body(1e+6, 2.67e+10);
	//if the body fails to create after the step above then it returns false
	if (body == nullptr) {
		return false;
	}
	return true;
}
//destroys the body and sets the pointer for body to null to free up memory when they are no longer needed
void Assignment1::OnDestroy() {
	
	if (body) {
		delete body;
		body = nullptr;
	}
}

void Assignment1::Update() {
	elapsedTime += time;
	/*if (elapsedTime <= 30.0) {*/
		body->force.Load(5e+7, 0, 0);
	/*}
	else*/
		if (elapsedTime > 30.0 && elapsedTime < 51.0) {
		body->torque = 6.291e+8;
	}
	else if (elapsedTime >= 51.0) {
		body->force.Load(0, 0, 0);
		body->torque = 0.0;
	}
	
	body->ApplyTorque(body->torque);
	body->Update(time);
	
	cout 
		<< setw(6) << elapsedTime
		<< setw(13) << setprecision(3) << body->torque
		<< setw(15) << setprecision(3) << body->angularAcc
		<< setw(13) << setprecision(3) << body->angularVel
		<< setw(13) << setprecision(3) << body->angle
		<< setw(13) << setprecision(3) << body->force.x
		<< setw(13) << setprecision(3) << body->force.y
		<< setw(13) << setprecision(3) << body->accel.x
		<< setw(13) << setprecision(3) << body->accel.y
		<< setw(13) << setprecision(3) << body->vel.x
		<< setw(13) << setprecision(3) << body->vel.y
		<< setw(13) << setprecision(3) << body->pos.x
		<< setw(13) << setprecision(3) << body->pos.y
	<< endl;
}

void Assignment1::Print() {
	//final method to print out every statistic through out the simulation
	cout
	<< setw(6) << "Time"
	<< setw(13) << "Torque"
	<< setw(13) << "Angular Acc"
	<< setw(13) << "Angular Vel"
	<< setw(13) << "Angle"
	<< setw(13) << "Force X"
	<< setw(13) << "Force Y"
	<< setw(13) << "Accel X"
	<< setw(13) << "Accel Y"
	<< setw(13) << "Vel X"
	<< setw(13) << "Vel Y"
	<< setw(13) << "Pos X"
	<< setw(13) << "Pos Y"
	<< endl;

}

void Assignment1::HandleEvents(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
	}
}