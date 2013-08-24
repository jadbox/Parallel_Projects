/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Registers

Data: 8/21/2013

*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <exception>

#include "RegisterSet.h"
using namespace std;


int main() {
	auto hello = "c++11 supported";
	cout << hello << endl; // prints !!!Hello World!!!

	try {

		RegisterSet r('i', 10); // define registers of type 'i' for integer and make 10 registers
		r.setr(1, new int(100)); // calls the inferred setr<int> uses the "new int" parameter given
		int x = r.getr(1).get_i();
		cout << "Reg1: " <<  x << endl; // calls getr with template int to extract the correct register value back

	} catch(const char* e) {
		cout << "error " << e;
	}
	return 0;
}
