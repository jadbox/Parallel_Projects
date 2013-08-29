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
#include "IllegalArgumentException.cpp"

using namespace std;

struct Register {
	void* raw; // void* is a pointer that points to register's data element
	bool z; // flag zero
	bool c; // flag carry
	bool n; // flag negative

	Register(size_t size) {
		z = c = n = false;
		raw = calloc(1, size); // allocate memory for register and initialize to 0
	}

	// Free the void* in the dtor
	~Register() {
		free(raw);
	}

	// When adding this to a vector, swap the data into the new register allocated by vector
	Register(const Register& r):raw(nullptr) {
		z = c = n = false;
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

class RegisterSet {
private:
	vector<Register> registers;
	size_t size;
	size_t number_of_registers;

public:
	// Ctor makes a bank of 9 32bit registers
	RegisterSet() {
		size = sizeof(long);
		number_of_registers = 9;
		reset();
	}
	// Ctor to make a register manager using a char code for the type
	RegisterSet(char type, size_t number_of_registers)
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
	// Ctor allows a user defined size of register, char type must be 'b'
	RegisterSet(char type, size_t size, size_t number_of_registers)
	:size(size), number_of_registers(number_of_registers) {
		if(type=='b') reset();
		else throw IllegalArgumentException("Invalid type, use 'b'");
	}
	// Get the Register object for the register index
	Register& get(size_t index) {
		if(index >= registers.size()-1) throw IllegalArgumentException("Index out of range"); // can't access more registered than available
		if(index==0) throw IllegalArgumentException("Cannot access 0 register"); // prevent register 0 access
		return registers[index]; // cast the void* to the appropriate type T from the template
	}
	// Set data directly into the Register object
	void set(size_t index, void* data) {
		if(index >= registers.size()-1) throw IllegalArgumentException("Index out of range"); // can't access more registered than available
		if(index==0) throw IllegalArgumentException("Cannot access 0 register"); // prevent register 0 access
		registers[index].raw = data;
	}

	void reset() {
		registers.clear(); // clear it out in case it's already been populated

		registers.reserve(number_of_registers); // reserve a mem block in the vector
		for(size_t i = 0; i < number_of_registers; i++) {
			registers.push_back( Register(size) );
		}
	}
};
