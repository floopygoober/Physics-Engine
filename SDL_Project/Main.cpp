#include <iostream>
#include <memory>
#include "Assignment1.h"
#include "MMath.h"
#include "VMath.h"
using namespace MATH;

int main(int argc, char* args[]) { /// Standard C-style entry point, you need to use it

	auto ass = std::unique_ptr<Assignment1>(new Assignment1());

	ass->Print();

	for (int i = 0; i < 60; i++) {
		ass->Update();
	}
	getchar();

	return 0;
}