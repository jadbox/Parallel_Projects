/*
 * Test.cpp
 *
 *  Created on: Sep 8, 2013
 *      Author: dunlap
 */

#include "Test.h"
#include <iostream>
using namespace std;

int errors = 0;

void test(bool test, const char* msg) {
	if(!test) {
		cout << "failed: " << msg << endl;
		++errors;
	}
	if(test) cout << "passed: " << msg << endl;
}
void test(bool test, const char* msg, const char* err) {
	if(!test) {
			cout << "Failed: " << err << endl;
			++errors;
	} else cout << "Passed: " << msg << endl;
}

void finish_tests(const char* testName) {
	cout << "== " << testName << " tests completed with " << errors << " errors" << endl;
	errors = 0;
}
