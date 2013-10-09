/*

Name: Jonathan Dunlap

Course: Introduction to Parallel and Cloud Computing

CRN: 75092

Assignment: Memory - Topic 2

Data: 9/3/2013

*/
#pragma once
#ifndef VMEMORY_H_
#define VMEMORY_H_

// Define registertype as unsigned int
typedef int registertype;

class Memory {
public:
	Memory();
	Memory(int* _data, unsigned int size);
	virtual ~Memory();
	int size();

	void write(unsigned int address, registertype value); // registertype defined by typedef
	registertype read(unsigned int address); // registertype defined by typedef

private:
	bool externalData;
	registertype *data;
	unsigned int memSize;

};

#endif /* VMEMORY_H_ */
