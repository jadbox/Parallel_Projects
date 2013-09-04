/*
 * ALU.cpp
 *
 *  Created on: Sep 3, 2013
 *      Author: jonathan
 */

#include "ALU.h"

ALU::ALU() {
	// TODO Auto-generated constructor stub

}

ALU::~ALU() {
	// TODO Auto-generated destructor stub
}

void ALU::LD (int Register, char prefix, int value){
	int rv, mv;
	switch(prefix) {
		case '0':
		case '\0':
			registerSet.set(Register, new int( *(int*)registerSet.get(value) ));
		break;
		case '@':
			rv = *(int*) registerSet.get(value);
			mv = memory.read(rv);
			registerSet.set(Register, new int(mv));
		break;
		case '#':
			registerSet.set(Register, new int(value));
		break;
	}
}
void ALU::ADD(int Register1, int Register2){
	int a = *(int*) registerSet.get(Register1);
	int b = *(int*) registerSet.get(Register2);
	int c = a + b;
	registerSet.set( Register1, new int(c) );
}

void ALU::SUB(int Register1, int Register2){
	int a = *(int*) registerSet.get(Register1);
	int b = *(int*) registerSet.get(Register2);
	int c = a - b;
	registerSet.set( Register1, new int(c) );
}

void ALU::MUL(int Register1, int Register2, int Register3){
	int a = *(int*) registerSet.get(Register1);
	int b = *(int*) registerSet.get(Register2);
	int c = (int) (a * b);
	registerSet.set( Register1, new int(c) );
}

void ALU::DIV(int Register1, int Register2, int Register3){
	int a = *(int*) registerSet.get(Register1);
	int b = *(int*) registerSet.get(Register2);
	int c = (int) (a / b);
	registerSet.set( Register1, new int(c) );
}

void ALU::STO(int Register1, int Register2){
	int a = *(int*) registerSet.get(Register1);
	int b = *(int*) registerSet.get(Register2);
	memory.write(b, a);
}
