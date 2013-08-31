/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: RegisterSet IllegalArgumentException

Data: 8/29/2013

*/

#include "IllegalArgumentException.h"

// Pass a string object to detail error state
IllegalArgumentException::IllegalArgumentException(const string& message)
	: invalid_argument(message) {}


