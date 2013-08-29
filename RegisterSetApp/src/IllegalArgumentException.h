/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: RegisterSet IllegalArgumentException

Data: 8/29/2013

*/

#ifndef ILLEGALARGUMENTEXCEPTION_H_
#define ILLEGALARGUMENTEXCEPTION_H_

#include <stdexcept>
#include <string>
using namespace std;

class IllegalArgumentException: public invalid_argument {
public:
	IllegalArgumentException(const string& message);
};

#endif /* ILLEGALARGUMENTEXCEPTION_H_ */
