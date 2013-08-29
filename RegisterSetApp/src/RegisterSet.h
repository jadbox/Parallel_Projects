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

struct Register {
	void* raw; // void* is a pointer that points to "something" that isn't specified. This allows Register
	bool flag_zero;
	bool flag_carry;
	bool flag_negative;

	Register(size_t size) {
		flag_zero = flag_carry = flag_negative = false;
		raw = calloc(1, size); // allocate memory for register and initialize to 0
	}

	// Free the void* in the dtor
	~Register() {
		free(raw);
	}

	// When adding this to a vector, swap the data into the new register allocated by vector
	Register(const Register& r):raw(nullptr) {
		flag_zero = flag_carry = flag_negative = false;
		auto& z = const_cast<Register&>(r);
		swap(raw, z.raw);
	}

	// Below are shorthands for casting the register to the correct type, out from void*
	int get_i() {
		return *static_cast<long*>(raw);
	}
	unsigned int get_u() {
		return *static_cast<unsigned long*>(raw);
	}
	long long get_l() {
		return *static_cast<long long*>(raw);
	}
	unsigned long long get_n() {
		return *static_cast<unsigned long long*>(raw);
	}
	unsigned long get_f() {
		return *static_cast<float*>(raw);
	}
	double get_d() {
		return *static_cast<double*>(raw);
	}
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
