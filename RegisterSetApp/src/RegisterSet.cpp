/*
 * RegistersSet.cpp
 *
 *  Created on: Aug 24, 2013
 *      Author: dunlap
 */
#include "RegisterSet.h"

// Ctor to make a register manager using a char code for the type
RegisterSet::RegisterSet(char type, size_t number_of_registers) {
	size_t unitSize = 0;

	switch(type) {
	case 'i':
		unitSize = sizeof(int); break;
	case 'u':
		unitSize = sizeof(unsigned int); break;
	case 'l':
		unitSize = sizeof(long); break;
	case 'n':
		unitSize = sizeof(unsigned long); break;
	case 'f':
		unitSize = sizeof(float); break;
	case 'd':
		unitSize = sizeof(double); break;
	default:
		throw("Invalid Type");
	}
	//memmove(registers+1, Register(unitSize), sizeof(Register));
	for(size_t i = 0; i < number_of_registers; i++) {
		auto r = Register(unitSize);
		registers.push_back( r );
		//registers[i] = Register(unitSize);
	}
}

// Destroy data
RegisterSet::~RegisterSet() {
	//for(auto r : registers) r._free();
}

// get data in the register
Register& RegisterSet::getr(size_t index) { // getr uses a template parameter to return a register slot
	if(index >= registers.size()-1) throw("Out of bounds"); // can't access more registered than available
	if(index==0) throw("Cannot access 0 register"); // prevent register 0 access
	return registers[index]; // cast the void* to the appropriate type T from the template
}

// set data in the register
void RegisterSet::setr(size_t index, void* data) { // gets the value of a register slot using the T template type
	if(index >= registers.size()-1) throw("Out of bounds"); // can't access more registered than available
	if(index==0) throw("Cannot access 0 register"); // prevent register 0 access
	registers[index].raw = data;
}
