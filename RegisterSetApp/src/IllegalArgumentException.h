/*
 * IllegalArgumentException.h
 *
 *  Created on: Aug 28, 2013
 *      Author: jonathan
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
