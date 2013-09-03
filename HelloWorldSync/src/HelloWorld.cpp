/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Hello World PTP

Data: 8/24/2013

*/

#include "HelloWorld.h"

HelloWorld::HelloWorld() {
}

void HelloWorld::sayit() {
	cout << "Hello World !" << endl;
}

int main() {
	cout << "started" << endl;

	HelloWorld hw;
	hw.sayit();
}
