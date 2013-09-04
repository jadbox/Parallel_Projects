/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: ALU - Topic 2

Data: 9/3/2013

*/

#include "ALU.h"
#include <climits>

ALU::ALU():memory(),registerSet() {


}

ALU::~ALU() {

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
	if(a + b > INT_MAX) registerSet.carryFlags[Register1] = true;
}

void ALU::SUB(int Register1, int Register2){
	int a = *(int*) registerSet.get(Register1);
	int b = *(int*) registerSet.get(Register2);
	int c = a - b;
	registerSet.set( Register1, new int(c) );
	if(a - b < 0) registerSet.negativeFlags[Register1] = true;
}

void ALU::MUL(int Register1, int Register2, int Register3){
	int a = *(int*) registerSet.get(Register1);
	int b = *(int*) registerSet.get(Register2);
	int c = (int) (a * b);
	registerSet.set( Register1, new int(c) );

	if(a * b > INT_MAX) {
		int r = a * b - INT_MAX;
		registerSet.set( Register3, new int(r) );
	}
}

void ALU::DIV(int Register1, int Register2, int Register3){
	int a = *(int*) registerSet.get(Register1);
	int b = *(int*) registerSet.get(Register2);
	int c = (int) (a / b);
	registerSet.set( Register1, new int(c) );

	int r = (int) a % b;
	registerSet.set( Register3, new int(r) );
}

void ALU::STO(int Register1, int Register2){
	int a = *(int*) registerSet.get(Register1);
	int b = *(int*) registerSet.get(Register2);
	memory.write(b, a);
}
