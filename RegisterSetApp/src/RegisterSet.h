/*
 * RegistersSet.h
 *
 *  Created on: Aug 24, 2013
 *      Author: dunlap
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

	unsigned int flags;

	Register(size_t size) {
		flag_zero = flag_carry = flag_negative = false;
		raw = calloc(1, size); // allocate memory for register and initialize to 0
		flags = 0;
	}
	~Register() {
		free(raw);
	}
	// When adding this to a vector, swap the data into the new register allocated by vector
	Register(const Register& r):raw(nullptr), flags(0) {
		flag_zero = flag_carry = flag_negative = false;
		auto& z = const_cast<Register&>(r);
		swap(raw, z.raw);
	}

	void _free() {
		free(raw);
	}
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
	// Makes a bank of 9 32bit registers
	RegisterSet();
	// Ctor to make a register manager using a char code for the type
	RegisterSet(char type, size_t number_of_registers);
	// Ctor
	RegisterSet(char type, size_t size, size_t number_of_registers);
	// get data in the register
	Register& getr(size_t index);
	// set data in the register
	void setr(size_t index, void* data);

	void reset();
};
