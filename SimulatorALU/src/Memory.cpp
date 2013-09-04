/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Memory - Topic 2

Data: 9/3/2013

*/

#include "Memory.h"
#include "IllegalArgumentException.h"

Memory::Memory() {
	// TODO Auto-generated constructor stub
	for(unsigned int i=0; i < MEM_SIZE; i++) data[i] = 0;
}

Memory::~Memory() {
	// TODO Auto-generated destructor stub
}

// registertype defined by typedef
void Memory::write(unsigned int address, registertype value) {
	if(address >= MEM_SIZE) throw IllegalArgumentException("index out of range");
	data[address] = value;
}

// registertype defined by typedef
registertype Memory::read(unsigned int address) {
	if(address >= MEM_SIZE) throw IllegalArgumentException("index out of range");
	return data[address];
}
