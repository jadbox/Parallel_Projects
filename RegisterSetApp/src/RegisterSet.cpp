/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: RegisterSet

Data: 8/29/2013

*/
#include "RegisterSet.h"

// Ctor to make a register manager using a char code for the type
RegisterSet::RegisterSet(char type, size_t number_of_registers)
:number_of_registers(number_of_registers) {

	switch(type) {
	case 'i':
		size = sizeof(long); break;
	case 'u':
		size = sizeof(unsigned long); break;
	case 'l':
		size = sizeof(long long); break;
	case 'n':
		size = sizeof(unsigned long long); break;
	case 'f':
		size = sizeof(float); break;
	case 'd':
		size = sizeof(double); break;
	default:
		throw("Invalid Type");
	}

	reset();
}

RegisterSet::RegisterSet(char type, size_t size, size_t number_of_registers)
:size(size), number_of_registers(number_of_registers) {
	if(type=='b') reset();
	else throw IllegalArgumentException("Invalid type, use 'b'");
}

RegisterSet::RegisterSet() {
	size = sizeof(long);
	number_of_registers = 9;
	reset();
}

void RegisterSet::reset() {
	registers.clear(); // clear it out in case it's already been populated
	size_t unitSize = 0;



	registers.reserve(number_of_registers);
	for(size_t i = 0; i < number_of_registers; i++) {
		registers.push_back( Register(unitSize) );
	}
}

// get data in the register
Register& RegisterSet::getr(size_t index) { // getr uses a template parameter to return a register slot
	if(index >= registers.size()-1) throw IllegalArgumentException("Index out of range"); // can't access more registered than available
	if(index==0) throw IllegalArgumentException("Cannot access 0 register"); // prevent register 0 access
	return registers[index]; // cast the void* to the appropriate type T from the template
}

// set data in the register
void RegisterSet::setr(size_t index, void* data) { // gets the value of a register slot using the T template type
	if(index >= registers.size()-1) throw IllegalArgumentException("Index out of range"); // can't access more registered than available
	if(index==0) throw IllegalArgumentException("Cannot access 0 register"); // prevent register 0 access
	registers[index].raw = data;
}
