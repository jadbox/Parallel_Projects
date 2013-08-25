/*
 * HelloWorld.cpp
 *
 *  Created on: Aug 24, 2013
 *      Author: dunlap
 */

#include "HelloWorld.h"

HelloWorld::HelloWorld() {
	sayit();
}

void HelloWorld::sayit() {
	cout << "Hello, Professor Brown.";
}

int main() {
	HelloWorld hw();
	hw.sayit();
}
