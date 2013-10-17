/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Memory - Topic 2

Data: 9/3/2013

*/

#include "Memory.h"
#include "IllegalArgumentException.h"
#include <iostream>

Memory::Memory() {
	// TODO Auto-generated constructor stub
	externalData = false;
	memSize = 512;
	data = new int[memSize];
	for(unsigned int i=0; i < memSize; i++) data[i] = 0;
}

Memory::Memory(int _memSize):memSize(_memSize) {
	// TODO Auto-generated constructor stub
	externalData = false;
	data = new int[memSize];
	for(unsigned int i=0; i < memSize; i++) data[i] = 0;
}

int Memory::size() { return memSize; }

Memory::Memory(int* _data, unsigned int size) {
	externalData = true;
	data = _data;
	memSize = size;
	for(unsigned int i=0; i < memSize; i++) data[i] = 0;
}

Memory::~Memory() {
	if(!externalData) delete[] data; // if this call allocated the memory
}

// registertype defined by typedef
void Memory::write(unsigned int address, registertype value) {
	if(address >= memSize) throw IllegalArgumentException("index out of range");
	data[address] = value;
}

// registertype defined by typedef
registertype Memory::read(unsigned int address) {
	if(address >= memSize) throw IllegalArgumentException("index out of range");
	return data[address];
}
