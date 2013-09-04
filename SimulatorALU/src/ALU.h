/*
 * ALU.h
 *
 *  Created on: Sep 3, 2013
 *      Author: jonathan
 */

#ifndef ALU_H_
#define ALU_H_

#include "RegisterSet.h"
#include "Memory.h"

class ALU {
public:
	ALU();
	virtual ~ALU();

	void LD (int Register, char prefix, int value);
	void ADD(int Register1, int Register2);
	void SUB(int Register1, int Register2);
	void MUL(int Register1, int Register2, int Register3);
	void DIV(int Register1, int Register2, int Register3);
	void STO(int Register1, int Register2);

private:
Memory memory;
RegisterSet registerSet;

};

#endif /* ALU_H_ */
