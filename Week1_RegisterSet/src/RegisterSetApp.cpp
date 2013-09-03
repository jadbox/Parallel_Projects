/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: RegisterSet

Data: 8/29/2013

*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <exception>

#include "RegisterSet.h"
using namespace std;


int main() {
	const char* hello = "c++11 supported";
	cout << hello << endl; // prints !!!Hello World!!!

	try {

		RegisterSet r; // define registers of type 'i' for integer and make 10 registers
		r.set(1, new int(100)); // calls the inferred setr<int> uses the "new int" parameter given
		int x = r.get(1).get_i();
		r.set(2, new int(1));
		int x2 = r.get(2).get_i();

		cout << "Reg1: " <<  x << " " << x2<< endl; // calls getr with template int to extract the correct register value back

	} catch(IllegalArgumentException& e) {
		cout << "error " << e.what();
	}
	return 0;
}
