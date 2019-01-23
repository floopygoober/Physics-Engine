#ifndef Assignment1_H
#define Assignment1_H

#include "MMath.h"

#include <SDL.h>

using namespace MATH;
class Assignment1 {
private:
	SDL_Window *window;
	Matrix4 projectionMatrix;
	class Body* body;
	float elapsedTime;
	int w, h;
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	bool go = false;

public:
	Assignment1();
	~Assignment1();
	bool OnCreate();
	void OnDestroy();
	void Update();
	void Print();
	virtual void HandleEvents(SDL_Event);
};

#endif

