/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: RegisterSet IllegalArgumentException

Data: 8/29/2013

*/

#include <stdexcept>
#include <string>
using namespace std;

// Extends invalid_argument
class IllegalArgumentException: public invalid_argument {
public:
	IllegalArgumentException(const string& message): invalid_argument(message) {}
};


