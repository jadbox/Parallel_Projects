/*

Name: Lauren Kroll

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: RegisterSet.h

Date: 8/29/13

*/

#pragma once
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class RegisterSet {

private:
	vector<void*> registers;
	size_t size;
	int count;

public:
	vector<bool> carryFlags;
	vector<bool> zeroFlags;
	vector<bool> negativeFlags;

	RegisterSet();
	RegisterSet(char type, int count);
	RegisterSet(char type, int size, int count);
	void set(int registerIndex, void* value);
	void* get(int registerIndex);
	void reset();

};
