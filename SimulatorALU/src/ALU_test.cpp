/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ALU - Topic 2

Data: 9/3/2013

*/

#include "ALU.h"
#include "IllegalArgumentException.h"
#include <iostream>
#include <cassert>
#include "utils\HPTimer.h"
#include "utils\Test.h"
using namespace std;

void alu_bench() {
	ALU alu;
	double time = HPTimer::get_time();
	for(int i=0; i < 512*850; i++) {
		alu.LD(1, '#', i%512); // literal value to add
		alu.LD(2, '#', i); // literal value to add
		alu.LD(5, '#', 511); // memory address
		alu.ADD(1,2); // add these two into reg 1
		alu.STO(1, 5); // put
	}
	double r = HPTimer::get_time();

	cout << "Benchmark alu add 	: " << r-time << " ~0.0306486" <<endl;

	time = HPTimer::get_time();
	for(int i=0; i < 512*850; i++) {
		alu.LD(1, '#', i%512); // literal value to add
		alu.LD(2, '#', i); // literal value to add
		alu.LD(5, '#', 111); // memory address
		alu.MUL(1,2,3); // add these two into reg 1
		alu.STO(1, 5); // put
	}
	r = HPTimer::get_time();
	cout << "Benchmark alu mutli	: " << r - time << " ~0.030205" << endl;
}

void ALU_test() {
	ALU alu;
	cout << "Instanced ALU" << endl;
	// Reg copy
	alu.LD(9, '#', 555);
	alu.LD(8, '0', 9);
	alu.LD(5, '#', 511);
	alu.STO(8, 5);
	test( alu.memory.read(511) == 555, "Reg copy test");

	// Mem lookup
	alu.memory.write(511, 555); // 511 holds 555
	alu.LD(5, '#', 511);
	alu.LD(8, '@', 5); // get the m555 value, from the mem address of reg5
	alu.LD(5, '#', 100); // make answer mem location
	alu.STO(8, 5); // put reg8 into reg5 mem address
	test( alu.memory.read(100) == 555, "Mem lookup test");

	//==== ADD
	alu.LD(1, '#', 123); // literal value to add
	alu.LD(2, '#', 222); // literal value to add
	alu.LD(5, '#', 511); // memory address
	alu.ADD(1,2); // add these two into reg 1
	alu.STO(1, 5); // put
	test( alu.memory.read(511) == 123+222, "ALU LD, ADD, STO test");

	//==== SUB
	alu.LD(1, '#', 100); // literal value to add
	alu.LD(2, '#', 40); // literal value to add
	alu.LD(5, '#', 0); // memory address
	alu.SUB(1,2); // add these two into reg 1
	alu.STO(1, 5); // put
	test( alu.memory.read(0) == 100-40, "ALU LD, SUB, STO test");

	//==== MULTI
	alu.LD(1, '#', 100); // literal value to add
	alu.LD(2, '#', 20); // literal value to add
	alu.LD(5, '#', 0); // memory address
	alu.MUL(1,2,3); // add these two into reg 1
	alu.STO(1, 5); // put
	//cout <<  alu.memory.read(0) << endl;
	test( alu.memory.read(0) == 2000, "ALU LD, MUL, STO test");

	//==== DIV
	alu.LD(1, '#', 100); // literal value to add
	alu.LD(2, '#', 20); // literal value to add
	alu.LD(5, '#', 1); // memory address
	alu.DIV(1,2,3); // add these two into reg 1
	alu.STO(1, 5); // put
	//cout <<  alu.memory.read(0) << endl;
	test( alu.memory.read(1) == 5, "ALU LD, DIV, STO test");

	finish_tests("ALU");
	alu_bench();
}
