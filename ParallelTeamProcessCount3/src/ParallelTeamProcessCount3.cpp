/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ParallelTeam

Data: 10/06/2013

*/

#include <iostream>
#include "ParallelTeam.h"
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	ParallelTeam pt;
	pt.createProcessTeam(5);

	return 0;
}
