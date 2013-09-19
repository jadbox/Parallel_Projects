//============================================================================
// Name        : ParallelTeamApp.cpp
// Author      : Jonathan Dunlap
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ParallelTeam.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	ParallelTeam pt;
	pt.createProcessTeam(5);

	return 0;
}
