//============================================================================
// Name        : SimulatorALU.cpp
// Author      : Jonathan Dunlap
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ALU.h"

using namespace std;



int main_main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
//===================



///============
void Memtest(), ALU_test(), CTAMemtest();

int main(int num, const char** args) {
	Memtest();
	cout << endl;
	CTAMemtest();
	cout << endl;
	ALU_test();
	return 0;
}
