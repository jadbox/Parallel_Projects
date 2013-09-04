/*

Name: Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: RegisterSet.cpp

Date: 8/29/13

*/

#include "IllegalArgumentException.h"
#include "RegisterSet.h"


RegisterSet::RegisterSet() {
	size = sizeof(long);
	count = 9;
	reset();
}
RegisterSet::RegisterSet(char type, int count):count(count) {

	switch (type) {
	//i -  signed 32 bit integer
	case 'i':
		size = sizeof(int);
		break;
		//u - unsigned 32 bit integer
	case 'u':
		size = sizeof(unsigned int);
		break;
		//l - signed 64 bit integer
	case 'l':
		size = sizeof(long long);
		break;
		//n - unsigned 64 bit integer
	case 'n':
		size = sizeof(unsigned long long);
		break;
		//f - 32 bit floating point
	case 'f':
		size = sizeof(float);
		break;
		//d - 64 bit floating point
	case 'd':
		size = sizeof(double);
		break;
	default:
		size = sizeof(long);
	}
	reset();
}

RegisterSet::RegisterSet(char type, int size, int count):size(size),count(count) {
	if (type == 'b') reset();
	else throw IllegalArgumentException("Invalid type");
}

void RegisterSet::set(int registerIndex, void* value) {
	if (registerIndex != 0) registers[registerIndex] = value;
	else throw IllegalArgumentException("Index out of range");
}

void* RegisterSet::get(int registerIndex) {
	if (registerIndex != 0) return registers[registerIndex];
	else throw IllegalArgumentException("Index out of range");
}

void RegisterSet::reset() {
	//clean registers
	registers.clear();
	carryFlags.clear();
	zeroFlags.clear();
	negativeFlags.clear();
	for (int i = 0; i < count; i++) {
		//manage flags
		carryFlags.push_back(false);
		zeroFlags.push_back(false);
		negativeFlags.push_back(false);
		//allocate and push
		void* data = calloc (1,size);
		registers.push_back(data);
	}
}

