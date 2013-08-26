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

using namespace std;

struct Register {
	void* raw; // void* is a pointer that points to "something" that isn't specified. This allows Register

	Register(size_t size) {
		raw = calloc(1, size); // allocate memory for register and initialize to 0
	}
	~Register() {
		free(raw);
	}
	// When adding this to a vector, swap the data into the new register allocated by vector
	Register(const Register& r):raw(nullptr) {
		auto& z = const_cast<Register&>(r);
		swap(raw, z.raw);
	}
	void _free() {
		free(raw);
	}
	int get_i() {
		return *static_cast<int*>(raw);
	}
	unsigned int get_u() {
		return *static_cast<unsigned int*>(raw);
	}
	long get_l() {
		return *static_cast<long*>(raw);
	}
	unsigned long get_n() {
		return *static_cast<unsigned long*>(raw);
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

public:
	// Ctor to make a register manager using a char code for the type
	RegisterSet(char type, size_t number_of_registers);
	// get data in the register
	Register& getr(size_t index);
	// set data in the register
	void setr(size_t index, void* data);
};
