/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: RegisterSet

Data: 8/29/2013

*/
#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include "IllegalArgumentException.h"

using namespace std;

// ==== Register Helper
struct Register {
	void* raw; // void* is a pointer that points to "something" that isn't specified. This allows Register
	bool flag_zero;
	bool flag_carry;
	bool flag_negative;

	Register(size_t size);

	// Free the void* in the dtor
	~Register();

	// When adding this to a vector, swap the data into the new register allocated by vector
	Register(const Register& r);

	// Below are shorthands for casting the register to the correct type, out from void*
	int& get_i();
	unsigned int& get_u();
	long long& get_l();
	unsigned long long& get_n();
	float& get_f();
	double& get_d();
};

struct RegisterSet {
private:
	vector<Register> registers;
	size_t size;
	size_t number_of_registers;

public:
	// Ctor makes a bank of 9 32bit registers
	RegisterSet();
	// Ctor to make a register manager using a char code for the type
	RegisterSet(char type, size_t number_of_registers);
	// Ctor allows a user defined size of register, char type must be 'b'
	RegisterSet(char type, size_t size, size_t number_of_registers);
	// Get the Register object for the register index
	Register& get(size_t index);
	// Set data directly into the Register object
	void set(size_t index, void* data);

	void reset();
};
