/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: CTAMemory - Topic 2

Data: 9/9/2013

*/

#include "CTAMemory.h"
#include "IllegalArgumentException.h"
#include <iostream>
#include <cassert>
#include "utils\HPTimer.h"
#include "utils\Test.h"
using namespace std;


void CTAbench() {
	CTAMemory memory;
	double time = HPTimer::get_time();
	for(int i=0; i < 512*150; i++) {
		memory.write(i%512, i);
	}
	double r = HPTimer::get_time();

	cout << "Benchmark mem write 	: " << r-time << " ~0.00152616" <<endl;

	int total=0;
	time = HPTimer::get_time();
	for(int i=0; i < 512*150; i++) {
		total += memory.read(i%512);
	}
	r = HPTimer::get_time();
	cout << "Benchmark read		: " << r-time << " ~0.00154098" << endl;
	cout << "Ignore: checksum: " << total << endl;
}

void CTAMemtest() {
	cout << "Instancing CTAMemory" << endl;
	CTAMemory memory;
	test(0 == memory.read(0), "Checking initialized memory values");

	memory.write(0, 10);
	test(10 == memory.read(0), "Write 10 to a0 and read it back");

	memory.write(511, 55555);
	test(55555 == memory.read(511), "Write 55555 to a511 and read it back");

	bool passed = false;
	try {
		memory.read(512); // +1 over limit (starts from 0)
	} catch(IllegalArgumentException& e) {
		passed = true;
		cout << "Passed correctly with out of bounds 512 index error: " << e.what() << endl;
	}
	if(!passed) assert("No thrown exception");

	finish_tests("CTAMemory");

	CTAbench();
}
